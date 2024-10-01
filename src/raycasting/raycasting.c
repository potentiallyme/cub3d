/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:41:11 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/01 18:34:57 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	adjust_inter(double angle, double *inter, double *step, int h)
{
	if (h)
	{
		if (angle > 0 && angle < M_PI)
		{
			inter += TILE_SIZE;
			return (FAIL);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
				inter += TILE_SIZE;
				return (FAIL);
		}
		*step *= -1;
	}
	return (SUCCESS);
}

double	get_h_inter(t_mlx *mlx, double angle)//!
{
	double	x;
	double	y;
	double	x_step;
	double	y_step;
	int		wall_res;

	printf("get_h_inter>angle: %f\n", angle);
	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	y = floor(mlx->ply->ply_y / TILE_SIZE) * TILE_SIZE;
	wall_res = adjust_inter(angle, &y, &y_step, 1); //make sure point is on the horizontal line
	x = mlx->ply->ply_x + ((y - mlx->ply->ply_y) / tan(angle));
	
	printf("mlx->ply->ply_x:%d, mlx->ply->ply_y x: %d\n", mlx->ply->ply_x, mlx->ply->ply_y);
	
	if ((check_direction(angle, 'y') == TRUE && x_step > 0)
		|| ((check_direction(angle, 'y') == FALSE && x_step < 0)))
		x_step *= -1;

	printf("BEFORE x: %f, y: %f\n", x, y);
	
	while (wall_hit(mlx, x, y - wall_res))
	{
		x += x_step;
		y += y_step;
	}
	printf("AFTER x: %f, y: %f\n", x, y);
	mlx->ray->horiz_x = x; //!new add>>missing
	mlx->ray->horiz_y = y; //!new add>>missing
	printf("horiz_x: %f, horiz_y: %f\n", mlx->ray->horiz_x,mlx->ray->horiz_y);
	return (sqrt(pow(x - mlx->ply->ply_x, 2) + pow(y - mlx->ply->ply_y, 2)));
}

double	get_v_inter(t_mlx *mlx, double angle)//!
{
	double	x;
	double	y;
	double	x_step;
	double	y_step;
	int		wall_res;

	printf("get_v_inter>angle: %f\n", angle);
	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	x = floor((mlx->ply->ply_x / TILE_SIZE) * TILE_SIZE);
	wall_res = adjust_inter(angle, &x, &x_step, 0); //make sure point is on the horizontal line
	y = mlx->ply->ply_y + (x - mlx->ply->ply_x) * tan(angle);
	if ((check_direction(angle, 'x') == TRUE && y_step < 0)
		|| (check_direction(angle, 'x') == FALSE && y_step > 0))
		y_step *= -1;
	printf("get_v_inter BEFORE x: %f, y: %f\n", x, y);
	while (wall_hit(mlx, x - wall_res, y))
	{
		x += x_step;
		y += y_step;
	}
	printf("AFTER x: %f, y: %f\n", x, y);
	mlx->ray->vert_x = x;//!new add
	mlx->ray->vert_y = y;//!new add
	printf("vert_x: %f, vert_y: %f\n", mlx->ray->vert_x,mlx->ray->vert_y);
	return (sqrt(pow(x - mlx->ply->ply_x, 2) + pow(y - mlx->ply->ply_y, 2)));

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
	printf("cast_rays>ply->angle: %f, ray_angle: %f, fov_radian: %f\n", mlx->ply->angle, mlx->ray->ray_angle, mlx->ply->fov_radian);
	while (ray < S_W)
	{
		mlx->ray->wall_flag = 0; //for rendering wall
		h_inter = get_h_inter(mlx, normalize_angle(mlx->ray->ray_angle));
		v_inter = get_v_inter(mlx, normalize_angle(mlx->ray->ray_angle));
		printf("cast_rays>h_inter: %f, v_inter: %f\n", h_inter, v_inter);
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
