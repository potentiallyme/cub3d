/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:30:37 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/07 16:44:40 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	move_player_forward(t_mlx *mlx)
{
	double	new_x;
	double	new_y;

	new_x = mlx->ply.ply_x + mlx->ply.dir_x * mlx->ply_speed;
	new_y = mlx->ply.ply_y + mlx->ply.dir_y * mlx->ply_speed;
	return (validate_move(mlx, new_x, new_y));
}

int	move_player_backward(t_mlx *mlx)
{
	double	new_x;
	double	new_y;

	new_x = mlx->ply.ply_x - mlx->ply.dir_x * mlx->ply_speed;
	new_y = mlx->ply.ply_y - mlx->ply.dir_y * mlx->ply_speed;
	return (validate_move(mlx, new_x, new_y));
}

int	move_player_left(t_mlx *mlx)
{
	double	new_x;
	double	new_y;

	new_x = mlx->ply.ply_x + mlx->ply.dir_y * mlx->ply_speed;
	new_y = mlx->ply.ply_y - mlx->ply.dir_x * mlx->ply_speed;
	return (validate_move(mlx, new_x, new_y));
}

int	move_player_right(t_mlx *mlx)
{
	double	new_x;
	double	new_y;

	new_x = mlx->ply.ply_x - mlx->ply.dir_y * mlx->ply_speed;
	new_y = mlx->ply.ply_y + mlx->ply.dir_x * mlx->ply_speed;
	return (validate_move(mlx, new_x, new_y));
}

int	move_player(t_mlx *mlx)
{
	int moved;
	
	moved = 0;
	if (mlx->ply.rot_r != 0)
		moved += rotate_view(mlx, mlx->ply.rot_r);
	if (mlx->ply.rot_l != 0)
		moved += rotate_view(mlx, mlx->ply.rot_l);
	if (mlx->ply.move_y == 1)
		moved += move_player_forward(mlx);
	if (mlx->ply.move_y == -1)
		moved += move_player_backward(mlx);
	if (mlx->ply.move_x == -1)
		moved += move_player_left(mlx);
	if (mlx->ply.move_x == 1)
		moved += move_player_right(mlx);
	return (moved);
}
