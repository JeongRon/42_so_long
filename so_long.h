/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:55:46 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/26 04:18:28 by jeongrol         ###   ########.fr       */
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


# define BUFFER_SIZE 42

typedef struct s_check_map
{
	int		c;
	int		e;
	int		p;
	int		col;
	int		row;
	int		p_index;
	int		dfs_count;
}	t_check_map;

int		error_msg(char *s);

int		check_ac_av(int ac, char *av);
void	initialize_map_info(t_check_map *info);

char	*read_map(int fd, t_check_map *info);
char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
void	free_all(char *a, char *b);
int		ft_strlen(const char *s);
int		ft_linelen(const char *s);
char	*ft_strjoin(char *join_buff, char *tmp, int tmp_len);

int		check_map_cnt(t_check_map *info);
int		check_map_wall(char *map, t_check_map info, int index);
int		check_map_dfs(char *map, t_check_map *info);

#endif