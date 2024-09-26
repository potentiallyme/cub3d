/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:41:11 by yu-chen           #+#    #+#             */
/*   Updated: 2024/09/26 16:33:58 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	adjust_inter(double angle, double inter, double step, int h)
{
	if (h)
	{
		if (angle > 0 && angle < M_PI)
			inter += TILE_SIZE;
		else
			step *= -1;
	}
	else
	{
		if ((angle > 0 && angle < M_PI / 2)
			|| ((angle > (3 * M_PI) / 2) && angle < 2 * M_PI))
			inter += TILE_SIZE;
		else
			step *= -1;
	}
	return (inter);
}

double	get_h_inter(t_mlx *mlx, double angle)//!
{
	double	h_x;
	double	h_y;
	double	x_step;
	double	y_step;
	int		wall_res;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	h_y = floor((mlx->ply->ply_y / TILE_SIZE) * TILE_SIZE);
	h_y = adjust_inter(angle, h_y, y_step, 1); //make sure point is on the horizontal line
	h_x = mlx->ply->ply_x + ((h_y - mlx->ply->ply_y) / tan(angle));
	if ((check_direction(angle, 'y') == 1 && x_step < 0)
		|| ((check_direction(angle, 'y') == -1 && x_step > 0)))
		x_step *= -1;
	while (1) //check if wall is hit
	{
		wall_res = wall_hit(mlx, h_x, h_y);
		// this was // * wall_hit(mlx, x, y) before, but x and y are undefiend, DOUBLE CHECK
		if (wall_res == 1)
			break ;
		else if (wall_res == -1)
			return (FLT_MAX);
		h_x += x_step;
		h_y += y_step;
	}
	mlx->ray->horiz_x = h_x; //!new add
	mlx->ray->horiz_y = h_y; //!new add
	return (sqrt(pow(h_x - mlx->ply->ply_x, 2) + pow(h_y - mlx->ply->ply_y, 2)));
}

double	get_v_inter(t_mlx *mlx, double angle)//!
{
	double	v_x;
	double	v_y;
	double	x_step;
	double	y_step;
	int		wall_res;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	v_x = floor((mlx->ply->ply_x / TILE_SIZE) * TILE_SIZE);
	v_x = adjust_inter(angle, v_x, x_step, 0); //make sure point is on the horizontal line
	v_y = mlx->ply->ply_y + ((v_x - mlx->ply->ply_x) * tan(angle));
	if ((check_direction(angle, 'x') == 1 && y_step < 0)
		|| (check_direction(angle, 'x') == -1 && y_step > 0))
		y_step *= -1;
	while (1) //check if wall is hit
	{
		wall_res = wall_hit(mlx, v_x, v_y);
		if (wall_res == 1)
			break ;
		else if (wall_res == -1)
			return (FLT_MAX);
		v_x += x_step;
		v_y += y_step;
	}
	mlx->ray->vert_x = v_x;//!new add
	mlx->ray->vert_y = v_y;//!new add
	return (sqrt(pow(v_x - mlx->ply->ply_x, 2) + pow(v_y - mlx->ply->ply_y, 2)));

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
	mlx->ray->ray_angle = mlx->ply->angle
		- (mlx->ply->fov_radian / 2); //start angle
	while (ray < S_W)
	{
		mlx->ray->wall_flag = 0; //for rendering wall
		h_inter = get_h_inter(mlx, normalize_angle(mlx->ray->ray_angle));
		v_inter = get_v_inter(mlx, normalize_angle(mlx->ray->ray_angle));
		if (v_inter <= h_inter)
			mlx->ray->distance = v_inter;
		else
		{
			mlx->ray->distance = h_inter;
			mlx->ray->wall_flag = 1; //for rendering wall
		}
		rendering(mlx, ray);
		ray++;
		mlx->ray->ray_angle += (mlx->ply->fov_radian / S_W);
	}
}
