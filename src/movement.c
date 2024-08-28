/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumi <yumi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:52:01 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/28 16:14:11 by yumi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

void	key_press(t_keydata keydata, void *ml)
{
	t_mlx *mlx;
	mlx = ml;
	if (keydata == KEY_ESC && (keydata.action == MLX_PRESS))
		ft_exit(mlx);
	else if (keydata.key == KEY_W && (keydata.action == MLX_PRESS))
		mlx->ply->u_d = 1;
	else if (keydata.key == KEY_S && (keydata.action == MLX_PRESS))
		mlx->ply->u_d = 1;
	else if (keydata.key == KEY_A && (keydata.action == MLX_PRESS))
		mlx->ply->l_r = -1;
	else if (keydata.key == KEY_D && (keydata.action == MLX_PRESS))
		mlx->ply->l_r = 1;
	else if (keydata.key == KEY_LEFT && (keydata.action == MLX_PRESS))
		mlx->ply->rot = -1;
	else if (keydata == KEY_RIGHT)
		mlx->ply->rot = 1;
	ft_release(keydata, mlx);
}

void	handle_ply_movement(t_mlx *mlx)
{
	double move_x;
	double move_y;

	//continue here
}