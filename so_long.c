/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:04:02 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/26 17:26:08 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	return (0);
}

void	put_img(t_check_map *map, int y, int x, char *file)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(map->mlx, file, &img_width, &img_height);
	if (!img)
	{
		printf("no img\n");
		return ;
	}
	mlx_put_image_to_window(map->mlx, map->win, img, y * 60, x * 60);
	mlx_destroy_image(map->mlx, img);
}

int	show_map(t_check_map *map)
{
	int		x;
	int		y;
	int		index;

	x = -1;
	index = 0;
	mlx_clear_window(map->mlx, map->win);
	while (++x < map->row)
	{
		y = -1;
		while (++y < map->col)
		{
			put_img(map, y, x, "./images/tile.xpm");
			if (map->line[index] == '1')
				put_img(map, y, x, "./images/wall.xpm");
			else if (map->line[index] == 'C')
				put_img(map, y, x, "./images/collect.xpm");
			else if (map->line[index] == 'P')
				put_img(map, y, x, "./images/patrol0.xpm");
			else if (map->line[index] == 'E')
				put_img(map, y, x, "./images/exit.xpm");
			else if (map->line[index] == 'N')
			{
				put_img(map, y, x, "./images/exit.xpm");
				put_img(map, y, x, "./images/patrol0.xpm");
			}
			index++;
		}
	}
	return (0);
}

int	exit_map(t_check_map *map)
{
	free(map);
	exit(0);
	return (0);
}

void	move_position(t_check_map *map, int move)
{
	if (map->line[move] == '1')
		return ;
	if (map->p_index != map->e_index)
		map->line[map->p_index] = '0';
	else
	{
		if (map->c == 0)
			exit(0);
		map->line[map->p_index] = 'E';
	}
	if (map->line[move] == '0')
		map->line[move] = 'P';
	else if (map->line[move] == 'C')
	{
		map->c--;
		map->line[move] = 'P';
	}
	else if (map->line[move] == 'E')
		map->line[move] = 'N';
	map->p_index = move;
	printf("movement : %d\n", ++map->map_count);
}

int	key_press(int keycode, t_check_map *map)
{
	if (keycode == KEY_W)
		move_position(map, map->p_index - map->col);
	if (keycode == KEY_S)
		move_position(map, map->p_index + map->col);
	if (keycode == KEY_A)
		move_position(map, map->p_index - 1);
	if (keycode == KEY_D)
		move_position(map, map->p_index + 1);
	if (keycode == KEY_ESC)
		exit_map(map);
	return (0);
}


void	run_mlx(t_check_map *map)
{
	mlx_hook(map->win, X_EVENT_KEY_PRESS, 0, &key_press, map);
	mlx_hook(map->win, X_EVENT_KEY_EXIT, 0, &exit_map, map);
	mlx_loop_hook(map->mlx, &show_map, map);
	mlx_loop(map->mlx);
}

int	main(int ac, char **av)
{
	int			fd;
	t_check_map	map;

	if (check_ac_av(ac, av[1]) == 0)
		return (0);
	initialize_map_info(&map);

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (error_msg("file open Error"));
	map.line = read_map(fd, &map);
	if (!map.line)
		return (0);
	if (check_map_cnt(&map) == 0 || check_map_wall(map.line, map, 0) == 0
		|| check_map_dfs(map.line, &map) == 0)
		return (0);
	map.mlx = mlx_init();
	if (!map.mlx)
		return (0);
	map.win = mlx_new_window(map.mlx, map.col * 60, map.row * 60, av[0]);
	if (!map.win)
		return (0);
	run_mlx(&map);
	return (0);
}
