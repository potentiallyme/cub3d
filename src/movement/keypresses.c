/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypresses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:52:01 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/11 14:28:32 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_walk_speed(t_mlx *mlx, int flag)
{
	if (flag == WALK)
	{
		mlx->ply_speed = 0.0125;
		mlx->rot_speed = 0.03;
		mlx->ply.sprint = 0;
	}
	else if (flag == RUN)
	{
		mlx->ply_speed = 0.0275;
		mlx->rot_speed = 0.035;
		mlx->ply.sprint = 1;
	}
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		ft_exit(mlx);
	if (keycode == XK_w && mlx->ply.move_y == 1)
		mlx->ply.move_y = 0;
	else if (keycode == XK_Left && mlx->ply.rot_l <= 1)
		mlx->ply.rot_l = 0;
	else if (keycode == XK_Right && mlx->ply.rot_r >= -1)
		mlx->ply.rot_r = 0;
	else if (keycode == XK_Shift_L)
		set_walk_speed(mlx, WALK);
	else if (keycode == XK_s && mlx->ply.move_y == -1)
		mlx->ply.move_y = 0;
	else if (keycode == XK_a && mlx->ply.move_x == -1)
		mlx->ply.move_x = 0;
	else if (keycode == XK_d && mlx->ply.move_x == 1)
		mlx->ply.move_x = 0;
	else if (keycode == XK_f && mlx->ply.fire == 1)
		mlx->ply.fire = 0;
	return (0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		ft_exit(mlx);
	else if (keycode == XK_Left)
		mlx->ply.rot_l += -1;
	else if (keycode == XK_Right)
		mlx->ply.rot_r += 1;
	else if (keycode == XK_w)
		mlx->ply.move_y = 1;
	else if (keycode == XK_s)
		mlx->ply.move_y = -1;
	else if (keycode == XK_a)
		mlx->ply.move_x = -1;
	else if (keycode == XK_d)
		mlx->ply.move_x = 1;
	else if (keycode == XK_Shift_L)
	{
		if (mlx->ply.gauge > 0)
			set_walk_speed(mlx, RUN);
	}
	else if (keycode == XK_f)
		mlx->ply.fire = 1;
	else if (keycode == XK_e)
		mlx->ply.door = 1;
	return (1);
}
