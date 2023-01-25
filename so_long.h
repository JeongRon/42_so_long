/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:55:46 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/25 21:43:00 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "mlx/mlx.h"

typedef struct s_check_map
{
	int		collect_cnt;
	int		exit_cnt;
	int		position_cnt;
	int		line_cnt;

}	t_check_map;

int	error_ac_msg(void);
int	error_av_msg(void);
int	error_fd_msg(void);

#endif