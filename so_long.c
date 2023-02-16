/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:04:02 by jeongrol          #+#    #+#             */
/*   Updated: 2023/02/16 07:41:32 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *s)
{
	write(2, "Error\n", 6);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	return (0);
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
		return (error_msg("File open failure"));
	map.line = read_map(fd, &map);
	if (!map.line || map.col == 0)
		return (error_msg("Invalid map OR Memory allocation failure (map)"));
	if (check_map_cnt(&map) == 0 || check_map_wall(map.line, map, 0) == 0
		|| check_map_dfs(map.line, &map) == 0)
		return (0);
	map.mlx = mlx_init();
	if (!map.mlx)
		return (error_msg("mlx failure"));
	map.win = mlx_new_window(map.mlx, map.col * 50, map.row * 50, av[0]);
	if (!map.win)
		return (error_msg("window failure"));
	run_mlx(&map);
	return (0);
}
