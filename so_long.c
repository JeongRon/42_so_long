/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:04:02 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/25 21:43:43 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i >= 5)
	{
		if (s[i - 1] == 'r' && s[i - 2] == 'e'
			&& s[i - 3] == 'b' && s[i - 4] == '.')
			return (1);
	}
	return (0);
}

char	*read_map(int fd)
{
	t_check_map	tmp;
	char		*buff;

	tmp.collect_cnt = 0;
	tmp.exit_cnt = 0;
	tmp.position_cnt = 0;
	tmp.line_cnt = 0;
	// buff = get_next_line(fd, tmp);
	return (buff);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*map;

	if (ac != 2)
		return (error_ac_msg());
	if (check_ber(av[1]) == 0)
		return (error_ber_msg());
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (error_fd_msg());
	map = read_map(fd);

	return (0);
}
