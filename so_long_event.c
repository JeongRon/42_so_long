/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:57:14 by jeongrol          #+#    #+#             */
/*   Updated: 2023/02/16 16:04:03 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	movement_write(int count)
{
	char	arr[11];
	int		i;

	write(1, "movement count : ", 17);
	i = 0;
	while (count / 10 != 0)
	{
		arr[i] = count % 10 + 48;
		count /= 10;
		i++;
	}
	arr[i] = count % 10 + 48;
	while (i != -1)
	{
		write(1, &arr[i], 1);
		i--;
	}
	write(1, "\n", 1);
}

static void	move_position(t_check_map *map, int move)
{
	if (map->line[move] == 'E')
	{
		if (map->c != 0)
			return ;
		else
			map->line[move] = 'P';
	}
	else if (map->line[move] == '1')
		return ;
	else if (map->line[move] == '0')
		map->line[move] = 'P';
	else if (map->line[move] == 'C')
	{
		map->c--;
		map->line[move] = 'P';
	}
	map->line[map->p_index] = '0';
	map->p_index = move;
	movement_write(++map->map_count);
	show_map(map, -1, -1, 0);
}

int	exit_map(t_check_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	free(map->line);
	exit(0);
	return (0);
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
