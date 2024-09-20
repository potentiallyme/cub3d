/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypresses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:52:01 by yu-chen           #+#    #+#             */
/*   Updated: 2024/09/20 17:41:00 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	rotate_view(t_mlx *mlx, int i)
{
	//add ROTATE_SPEED??
	if (i == 1)
	{
		if (mlx->ply->angle > 2 * M_PI)
			mlx->ply->angle -= 2 * M_PI;
	}
	else
	{
		if (mlx->ply->angle < 0)
			mlx->ply->angle += 2 * M_PI;
	}
}

int	key_release(int keycode, t_mlx *ml)
{
	if (keycode == XK_w)
		ml->ply->u_d = 0;
	else if (keycode == XK_s)
		ml->ply->u_d = 0;
	else if (keycode == XK_a)
		ml->ply->l_r = 0;
	else if (keycode == XK_d)
		ml->ply->l_r = 0;
	else if (keycode == XK_Left)
		ml->ply->rot = 0;
	else if (keycode == XK_Right)
		ml->ply->rot = 0;
	return (1);
}

int	key_press(int keycode, t_mlx *ml)
{
	if (keycode == 65307)
		ft_exit(ml);
	else if (keycode == XK_w && ml->ply->u_d == 0)
		ml->ply->u_d = -1;
	else if (keycode == XK_s && ml->ply->u_d == 0)
		ml->ply->u_d = 1;
	else if (keycode == XK_a && ml->ply->l_r == 0)
		ml->ply->l_r = -1;
	else if (keycode == XK_d && ml->ply->l_r == 0)
		ml->ply->l_r = 1;
	else if (keycode == XK_Left && ml->ply->rot == 0)
		ml->ply->rot = -1;
	else if (keycode == XK_Right && ml->ply->rot == 0)
		ml->ply->rot = 1;
	return (1);
}

void	move_player(t_mlx *mlx, double move_x, double move_y)
{
	int	new_x;
	int	new_y;
	int	map_array_x;
	int	map_array_y;

	new_x = roundf(mlx->ply->ply_x + move_x);
	new_y = roundf(mlx->ply->ply_y + move_y);
	map_array_x = new_x / TILE_SIZE;
	map_array_y = new_y / TILE_SIZE;
	if (mlx->data->map2d[map_array_y][map_array_x] != '1') //add other conditions?
	{
		mlx->ply->ply_x = new_x;
		mlx->ply->ply_y = new_y;
	}
}

void	handle_ply_movement(t_mlx *mlx, double move_x, double move_y)
{
	//add PLAYER_SPEED??
	if (mlx->ply->rot == 1)
		rotate_view(mlx, 1);
	if (mlx->ply->rot == -1)
		rotate_view(mlx, -1);
	if (mlx->ply->l_r == 1)
	{
		move_x = -sin(mlx->ply->angle);
		move_y = cos(mlx->ply->angle);
	}
	if (mlx->ply->l_r == -1)
	{
		move_x = sin(mlx->ply->angle);
		move_y = -cos(mlx->ply->angle);
	}
	if (mlx->ply->u_d == 1)
	{
		move_x = cos(mlx->ply->angle);
		move_y = sin(mlx->ply->angle);
	}
	if (mlx->ply->u_d == -1)
	{
		move_x = -cos(mlx->ply->angle);
		move_y = -sin(mlx->ply->angle);
	}
	move_player(mlx, move_x, move_y);
}
