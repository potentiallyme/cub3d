/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypresses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:52:01 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/01 17:51:43 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	rotate_view(t_mlx *mlx, int i)
{
	//add ROTATE_SPEED??Yes!!but why
	if (i == 1)
	{
		mlx->ply->angle += ROTATION_SPEED;
		if (mlx->ply->angle > 2 * M_PI)
			mlx->ply->angle -= 2 * M_PI;
	}
	else
	{
		mlx->ply->angle -= ROTATION_SPEED;
		if (mlx->ply->angle < 0)
			mlx->ply->angle += 2 * M_PI;
	}
	// printf("after rotate angle: %f\n", mlx->ply->angle);
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
	else if (keycode == XK_w)
		ml->ply->u_d = 1;
	else if (keycode == XK_s)
		ml->ply->u_d = -1;
	else if (keycode == XK_a)
		ml->ply->l_r = -1;
	else if (keycode == XK_d)
		ml->ply->l_r = 1;
	else if (keycode == XK_Left)
		ml->ply->rot = -1;
	else if (keycode == XK_Right)
		ml->ply->rot = 1;
	return (1);
}

void	move_player(t_mlx *mlx, double move_x, double move_y) //! add square_map check?
{
	int	new_x;
	int	new_y;
	int	map_array_x;
	int	map_array_y;

	new_x = roundf(mlx->ply->ply_x + move_x);
	new_y = roundf(mlx->ply->ply_y + move_y);
	// printf("ply_x:%i, ply_y:%i\n", mlx->ply->ply_x, mlx->ply->ply_y);
	// printf("move_x:%f, move_y:%f\n", move_x, move_y);
	// printf("new_x:%i, new_y:%i\n", new_x, new_y);
	map_array_x = new_x / TILE_SIZE;
	map_array_y = new_y / TILE_SIZE;
	if (mlx->data->map2d[map_array_y][map_array_x] != '1'
		&& mlx->data->square_map[map_array_y][mlx->ply->ply_x / TILE_SIZE] != '1'
		&& mlx->data->square_map[mlx->ply->ply_y / TILE_SIZE][map_array_x] != '1') //add other conditions with square_map?
	{
		mlx->ply->ply_x = new_x;
		mlx->ply->ply_y = new_y;
	}
}

void	handle_ply_movement(t_mlx *mlx, double move_x, double move_y)
{
	// printf("rot flag: %i, l_r flag: %i, u_d flag: %i\n", mlx->ply->rot, mlx->ply->l_r, mlx->ply->u_d);
	if (mlx->ply->rot == 1)
		rotate_view(mlx, 1);
	if (mlx->ply->rot == -1)
		rotate_view(mlx, 0);
	if (mlx->ply->l_r == 1)
	{
		move_x = -sin(mlx->ply->angle) * PLAYER_SPEED;
		move_y = cos(mlx->ply->angle) * PLAYER_SPEED;
	}
	if (mlx->ply->l_r == -1)
	{
		move_x = sin(mlx->ply->angle) * PLAYER_SPEED;
		move_y = -cos(mlx->ply->angle) * PLAYER_SPEED;
	}
	if (mlx->ply->u_d == 1)
	{
		move_x = cos(mlx->ply->angle) * PLAYER_SPEED;
		move_y = sin(mlx->ply->angle) * PLAYER_SPEED;
	}
	if (mlx->ply->u_d == -1)
	{
		move_x = -cos(mlx->ply->angle) * PLAYER_SPEED;
		move_y = -sin(mlx->ply->angle) * PLAYER_SPEED;
	}
	// printf("angle: %f, x: %f, y: %f\n", mlx->ply->angle, move_x, move_y);
	move_player(mlx, move_x, move_y);
}
