/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 04:07:44 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/26 17:01:09 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_line(char *line, int line_len, t_check_map *info, int i)
{
	if (info->col == 0)
		info->col = line_len;
	else
		if (info->col != line_len)
			return (error_msg("rectangle Error"));
	while (++i < line_len)
	{
		if (line[i] == '0' || line[i] == '1')
			continue ;
		else if (line[i] == 'C')
			info->c++;
		else if (line[i] == 'E')
		{
			info->e++;
			info->e_index = ((info->row - 1) * line_len) + i;
		}
		else if (line[i] == 'P')
		{
			info->p++;
			info->p_index = ((info->row - 1) * line_len) + i;
		}
		else
			return (error_msg("wrong character Error"));
	}
	return (1);
}

static int	so_long_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	*read_map(int fd, t_check_map *info)
{
	char		*map_buff;
	char		*line;
	int			line_len;

	map_buff = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_len = so_long_strlen(line);
		info->row++;
		if (check_line(line, line_len, info, -1) == 1)
			map_buff = ft_strjoin(map_buff, line, line_len);
		else
		{
			free(map_buff);
			map_buff = NULL;
			break ;
		}
	}
	free(line);
	return (map_buff);
}
