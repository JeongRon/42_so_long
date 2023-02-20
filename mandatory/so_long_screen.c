/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:57:11 by jeongrol          #+#    #+#             */
/*   Updated: 2023/02/20 19:55:54 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_check_map *map, int y, int x, char *file)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(map->mlx, file, &img_width, &img_height);
	if (!img)
		return ;
	mlx_put_image_to_window(map->mlx, map->win, img, y * 50, x * 50);
	mlx_destroy_image(map->mlx, img);
}

void	categorize_case(t_check_map *map, int x, int y, int index)
{
	if (map->line[index] == '0')
		put_img(map, y, x, "./images/tile.xpm");
	else if (map->line[index] == '1')
		put_img(map, y, x, "./images/wall.xpm");
	else if (map->line[index] == 'E')
	{
		put_img(map, y, x, "./images/tile.xpm");
		put_img(map, y, x, "./images/exit.xpm");
	}
	else if (map->line[index] == 'C')
	{
		put_img(map, y, x, "./images/tile.xpm");
		if (index % 2 == 0)
			put_img(map, y, x, "./images/collect0.xpm");
		else
			put_img(map, y, x, "./images/collect1.xpm");
	}
	else if (map->line[index] == 'P')
	{
		put_img(map, y, x, "./images/tile.xpm");
		put_img(map, y, x, "./images/p_down.xpm");
	}
}

int	show_map(t_check_map *map, int x, int y, int index)
{
	mlx_clear_window(map->mlx, map->win);
	while (++x < map->row)
	{
		y = -1;
		while (++y < map->col)
		{
			categorize_case(map, x, y, index);
			index++;
		}
	}
	if (map->line[map->p_index] == map->line[map->e_index] && map->c == 0)
		return (exit_map(map));
	return (0);
}

void	run_mlx(t_check_map *map)
{
	show_map(map, -1, -1, 0);
	mlx_hook(map->win, X_EVENT_KEY_PRESS, 0, &key_press, map);
	mlx_hook(map->win, X_EVENT_KEY_EXIT, 0, &exit_map, map);
	mlx_loop(map->mlx);
}
