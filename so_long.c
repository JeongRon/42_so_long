/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:04:02 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/26 04:23:55 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	return (0);
}

int	main(int ac, char **av)
{
	int			fd;
	char		*map;
	t_check_map	map_info;

	if (check_ac_av(ac, av[1]) == 0)
		return (0);
	initialize_map_info(&map_info);

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (error_msg("file open Error"));
	map = read_map(fd, &map_info);
	if (!map)
		return (0);
	if (check_map_cnt(&map_info) == 0 || check_map_wall(map, map_info, 0) == 0
		|| check_map_dfs(map, &map_info) == 0)
		return (0);
	free(map);
	return (0);
}
