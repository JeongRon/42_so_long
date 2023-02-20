/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ready.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 04:07:44 by jeongrol          #+#    #+#             */
/*   Updated: 2023/02/16 03:40:57 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map_info(t_check_map *info)
{
	info->c = 0;
	info->e = 0;
	info->p = 0;
	info->col = 0;
	info->row = 0;
	info->p_index = 0;
	info->e_index = 0;
	info->dfs_count = 0;
	info->map_count = 0;
}

int	check_ac_av(int ac, char *av)
{
	int	i;

	if (ac != 2)
		return (error_msg("ac Error"));
	i = 0;
	while (av[i] != '\0')
		i++;
	if (i >= 5)
	{
		if (av[i - 1] == 'r' && av[i - 2] == 'e'
			&& av[i - 3] == 'b' && av[i - 4] == '.')
			return (1);
	}
	return (error_msg("ber Error"));
}
