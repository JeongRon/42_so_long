/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:41:59 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/25 21:42:35 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_ac_msg(void)
{
	write(1, "argc input Error\n", 9);
	return (0);
}

int	error_av_msg(void)
{
	write(1, ".ber Error\n", 11);
	return (0);
}

int	error_fd_msg(void)
{
	write(1, "file open Error\n", 16);
	return (0);
}
