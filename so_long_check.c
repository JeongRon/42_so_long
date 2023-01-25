/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 04:13:25 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/26 04:31:36 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_cnt(t_check_map *info)
{
	if (info->c == 0)
		return (error_msg("collect Error"));
	else if (info->e != 1)
	{
		printf("exit : %d\n", info->e);
		return (error_msg("exit Error"));
	}
	else if (info->p != 1)
		return (error_msg("start position Error"));
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
					return (error_msg("wall Error"));
			}
			else
			{
				if (j == 1 || j == info.col)
					if (map[index] != '1')
						return (error_msg("wall Error"));
			}
			index++;
		}
	}
	return (1);
}

static int	dfs_direction(int d, t_check_map *info)
{
	int	end_index;
	int	start_index;

	start_index = 0;
	end_index = info->row * info->col - 1;
	if (start_index <= d && d <= end_index)
		return (1);
	return (0);
}

static void	dfs_run(char *dfs_map, t_check_map *info, int index)
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
	if (dfs_map[index] == 'E')
		return ;
	if (dfs_direction(up, info) && dfs_map[up] != '1')
		dfs_run(dfs_map, info, up);
	if (dfs_direction(down, info) && dfs_map[down] != '1')
		dfs_run(dfs_map, info, down);
	if (dfs_direction(left, info) && dfs_map[left] != '1')
		dfs_run(dfs_map, info, left);
	if (dfs_direction(right, info) && dfs_map[right] != '1')
		dfs_run(dfs_map, info, right);
}

int	check_map_dfs(char *map, t_check_map *info)
{
	char	*dfs_map;

	dfs_map = ft_strdup(map);
	dfs_run(dfs_map, info, info->p_index);
	free(dfs_map);
	if (info->dfs_count != info->c + info->e)
		return (error_msg("invalid path map Error"));
	return (1);
}
