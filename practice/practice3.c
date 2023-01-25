/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:27:12 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/25 21:35:07 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../mlx/mlx.h"

// miniLibX - 이미지 출력
int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "putImage");
	img = mlx_xpm_file_to_image(mlx, "images/collectible.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "images/tile.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "images/collectible3.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "images/tile.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 15, 15);
	mlx_put_image_to_window(mlx, win, img2, 60, 0);
	mlx_put_image_to_window(mlx, win, img4, 60, 60);
	mlx_put_image_to_window(mlx, win, img4, 75, 75);
	mlx_loop(mlx);
	return (0);
}
