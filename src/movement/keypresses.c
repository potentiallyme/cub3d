/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypresses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:52:01 by yu-chen           #+#    #+#             */
/*   Updated: 2024/09/17 16:14:08 by lmoran           ###   ########.fr       */
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

void	ft_release(t_keydata keydata, t_mlx *mlx)
{
	if (keydata.key == KEY_W && (keydata.action == KEY_RELEASE))
		mlx->ply->u_d = 0;
	else if (keydata.key == KEY_S && (keydata.action == KEY_RELEASE))
		mlx->ply->u_d = 0;
	else if (keydata.key == KEY_A && (keydata.action == KEY_RELEASE))
		mlx->ply->l_r = 0;
	else if (keydata.key == KEY_D && (keydata.action == KEY_RELEASE))
		mlx->ply->l_r = 0;
	else if (keydata.key == KEY_LEFT && keydata.action == KEY_RELEASE)
		mlx->ply->rot = 0;
	else if (keydata.key == KEY_RIGHT && keydata.action == KEY_RELEASE)
		mlx->ply->rot = 0;
}

void ft_exit(t_mlx *mlx)
{
	// temporary
	free_mlx(mlx, 0);
}

int	key_press(t_keydata keydata, void *ml)
{
	t_mlx *mlx;
	mlx = ml;
	if (keydata.key == KEY_ESC && (keydata.action == KEY_PRESS))
		ft_exit(mlx);
	else if (keydata.key == KEY_W && (keydata.action == KEY_PRESS))
		mlx->ply->u_d = 1;
	else if (keydata.key == KEY_S && (keydata.action == KEY_PRESS))
		mlx->ply->u_d = 1;
	else if (keydata.key == KEY_A && (keydata.action == KEY_PRESS))
		mlx->ply->l_r = -1;
	else if (keydata.key == KEY_D && (keydata.action == KEY_PRESS))
		mlx->ply->l_r = 1;
	else if (keydata.key == KEY_LEFT && (keydata.action == KEY_PRESS))
		mlx->ply->rot = -1; //rotation flag
	else if (keydata.key == KEY_RIGHT)
		mlx->ply->rot = 1; //rotation flag
	ft_release(keydata, mlx);
	return (1);
}

void	move_player(t_mlx *mlx, double move_x, double move_y)
{
	int	new_x;
	int	new_y;
	int map_array_x;
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

void	handle_ply_movement(t_mlx *mlx) //mlx_loop_hook->draw_map_pixel
{
	//add PLAYER_SPEED??
	double move_x;
	double move_y;

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
