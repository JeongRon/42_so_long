/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:55:46 by jeongrol          #+#    #+#             */
/*   Updated: 2023/02/20 18:51:14 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../mlx/mlx.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define BUFFER_SIZE 42

typedef struct s_check_map
{
	void	*mlx;
	void	*win;
	char	*line;
	int		c;
	int		e;
	int		p;
	int		col;
	int		row;
	int		p_index;
	int		e_index;
	int		dfs_count;
	int		map_count;
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

void	run_mlx(t_check_map *map);
int		show_map(t_check_map *map, int x, int y, int index);
void	categorize_case(t_check_map *map, int x, int y, int index);
void	put_img(t_check_map *map, int y, int x, char *file);

int		key_press(int keycode, t_check_map *map);
int		exit_map(t_check_map *map);

#endif