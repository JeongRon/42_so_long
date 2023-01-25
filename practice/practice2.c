/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:53:41 by jeongrol          #+#    #+#             */
/*   Updated: 2023/01/25 16:33:29 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define KEY_ESC 53
#define KEY_W 	13
#define KEY_S 	1
#define PRESS_RED_BUTTON 17

typedef struct	s_param
{
	int	x;
	int	y;
}	t_param;

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}

int	close(void)
{
	exit(0);
	return (0);
}

// miniLibX - 키보드 입력받고 출력하기
int	main(void)
{
	void	*mlx;
	void	*win;
	t_param	param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx 42");
	printf("-------------------------------\n");
	printf("Start x = 3\n");
	mlx_key_hook(win, &key_press, &param);
	mlx_hook(win, PRESS_RED_BUTTON, 0, &close, &param);
	mlx_loop(mlx);
}
