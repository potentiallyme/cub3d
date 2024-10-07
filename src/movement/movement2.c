/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:46:46 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/07 20:51:14 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	rotate_view(t_mlx *mlx, double rot_dir)
{
	t_player	*p;
	double		tmp_x;
	int		moved;
	double	rot_speed;

	moved = 0;
	rot_speed = mlx->rot_speed * rot_dir;
	p = &mlx->ply;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
	p->dir_y = tmp_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
	p->plane_y = tmp_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
	return (1);
}

int	validate_move(t_mlx *mlx, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(mlx->data.map2d, new_x, mlx->ply.ply_y) == TRUE)
	{
		mlx->ply.ply_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(mlx->data.map2d, mlx->ply.ply_x, new_y) == TRUE)
	{
		mlx->ply.ply_y = new_y;
		moved = 1;
	}
	return (moved);
}
