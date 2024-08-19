/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:41:11 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/19 16:28:56 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

check_inter()
{
	
}

double	get_h_inter(t_mlx *mlx, double angle)
{
	double	h_x,;
	double	h_y;
	double	x_step;
	double	y_step;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	h_y = floor((mlx->ply->p_y / TILE_SIZE) * TILE_SIZE);
	check_inter(); //make sure point is on the horizontal line
	h_x = mlx->ply->p_x + ((h_y - mlx->ply->p_y) / tan(angle));
	//check direction
	//check if wall is hit
	return (sqrt(pow(h_x - mlx->ply->p_x, 2) + pow(h_y - mlx->ply->p_y, 2)));
}

double	get_v_inter(t_mlx *mlx, double angle)
{
	double	v_x;
	double	v_y;
	double	x_step;
	double	y_step;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	v_x = floor((mlx->ply->p_x / TILE_SIZE) * TILE_SIZE);
	check_inter(); //make sure point is on the horizontal line
	v_y = mlx->ply->p_y + ((v_x - mlx->ply->p_x) * tan(angle));
	//check direction
	//check if wall is hit
	return (sqrt(pow(v_x - mlx->ply->p_x, 2) + pow(v_y - mlx->ply->p_y, 2)));

}

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	cast_rays(t_mlx *mlx)
{
	double	h_inter; //horizontal intersection
	double	v_inter; //vertical intersection
	int		ray;

	ray = 0;
	mlx->ray->ray_angle = mlx->ply->angle - (mlx->ply->fov_radian / 2);
	while (ray < S_W)
	{
		mlx->ray->wall_flag = 0;
		h_inter = get_h_inter(mlx, normalize_angle(mlx->ray->ray_angle));
		v_inter = get_v_inter(mlx, normalize_angle(mlx->ray->ray_angle));
		if (v_inter <= h_inter)
			mlx->ray->distance = v_inter;
		else
			mlx->ray->distance = h_inter;
		render_walls();
		ray++;
	}
}
