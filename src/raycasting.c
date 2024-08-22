/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:41:11 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/22 17:50:03 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	wall_hit(t_mlx *mlx, double x, double y)
{
	int	map_x;
	int	map_y;
	
	if (x < 0 || y < 0)
		return (-1); //over the map
	map_x = floor (x / TILE_SIZE);
	map_y = floor (y / TILE_SIZE);
	if (map_x >= mlx->data->map_w || map_y >= mlx->data->map_h)
		return (-1);
	if (mlx->data->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	check_direction(double angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI) //3&4 quadrant
			return (1);
	}
	if (c == 'y')
	{
		if ((angle > 0 && angle < M_PI / 2)
			|| (angle > (3 * M_PI) / 2 && angle < 2 * M_PI)) //1&4quadrant
			return (1);
	}
	return (-1);
}

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
			|| (angle > (3 * M_PI) / 2) && amgle < 2 * M_PI)
			inter += TILE_SIZE;
		else
			step *= -1;
	}
	return (inter);
}

double	get_h_inter(t_mlx *mlx, double angle)
{
	double	h_x;
	double	h_y;
	double	x_step;
	double	y_step;
	int		wall_res;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	h_y = floor((mlx->ply->p_y / TILE_SIZE) * TILE_SIZE);
	h_y = adjust_inter(angle, h_y, y_step, 1); //make sure point is on the horizontal line
	h_x = mlx->ply->p_x + ((h_y - mlx->ply->p_y) / tan(angle));
	if (check_direction(angle, 'y') == 1 && x_step < 0
		|| (check_direction(angle, 'y') == -1 && x_step > 0))
		x_step *= -1;
	while (1) //check if wall is hit
	{
		wall_res = wall_hit(mlx, x, y);
		if (wall_res == 1)
			break ;
		else if (wall_res == -1)
			return (FLT_MAX);
		h_x += x_step;
		h_y += y_step;
	}
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
	v_x = adjust_inter(angle, v_x, x_step, 0); //make sure point is on the horizontal line
	v_y = mlx->ply->p_y + ((v_x - mlx->ply->p_x) * tan(angle));
	if ((check_direction(angle, 'x') == 1 && y_step < 0)
		|| (check_direction(angle, 'x') == -1 && y_step > 0))
		y_step *= -1;
	while (1) //check if wall is hit
	{
		wall_res = wall_hit(mlx, x, y);
		if (wall_res == 1)
			break ;
		else if (wall_res == -1)
			return (FLT_MAX);
		v_x += x_step;
		v_y += y_step;
	}
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
		mlx->ray->ray_angle += mlx->ply->fov_radian / S_W;
	}
}
