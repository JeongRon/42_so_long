/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:31:32 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/25 16:33:43 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

// miniLibX 사용하여 창 띄워보기
int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_practice");
	return (0);
}
