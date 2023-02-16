/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 04:13:25 by jeongrol          #+#    #+#             */
/*   Updated: 2023/02/16 04:42:31 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_cnt(t_check_map *info)
{
	if (info->c == 0)
		return (error_msg("You must contain at least 1 Collectible"));
	else if (info->e != 1)
		return (error_msg("You must contain 1 Exit"));
	else if (info->p != 1)
		return (error_msg("You must contain 1 Starting Position"));
	return (1);
}

int	check_map_wall(char *map, t_check_map info, int index)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= info.row)
	{
		j = 0;
		while (++j <= info.col)
		{
			if (i == 1 || i == info.row)
			{
				if (map[index] != '1')
					return (error_msg("map must be surrounded by walls"));
			}
			else
			{
				if (j == 1 || j == info.col)
					if (map[index] != '1')
						return (error_msg("map must be surrounded by walls"));
			}
			index++;
		}
	}
	return (1);
}

static int	check_dfs_segfault(int d, t_check_map *info)
{
	int	end_index;
	int	start_index;

	start_index = 0;
	end_index = info->row * info->col - 1;
	if (start_index <= d && d <= end_index)
		return (1);
	return (0);
}

static void	check_dfs_run(char *dfs_map, t_check_map *info, int index)
{
	int	up;
	int	down;
	int	left;
	int	right;

	up = index - info->col;
	down = index + info->col;
	left = index - 1;
	right = index + 1;
	if (dfs_map[index] == 'C' || dfs_map[index] == 'E')
		info->dfs_count++;
	dfs_map[index] = '1';
	if (check_dfs_segfault(up, info) && dfs_map[up] != '1')
		check_dfs_run(dfs_map, info, up);
	if (check_dfs_segfault(down, info) && dfs_map[down] != '1')
		check_dfs_run(dfs_map, info, down);
	if (check_dfs_segfault(left, info) && dfs_map[left] != '1')
		check_dfs_run(dfs_map, info, left);
	if (check_dfs_segfault(right, info) && dfs_map[right] != '1')
		check_dfs_run(dfs_map, info, right);
}

int	check_map_dfs(char *map, t_check_map *info)
{
	char	*dfs_map;

	dfs_map = ft_strdup(map);
	if (!dfs_map)
	{
		free(dfs_map);
		return (error_msg("Memory allocation failure(dfs_map)"));
	}
	check_dfs_run(dfs_map, info, info->p_index);
	free(dfs_map);
	if (info->dfs_count != info->c + info->e)
		return (error_msg("Invalid path map"));
	return (1);
}
