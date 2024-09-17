/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:45 by yu-chen           #+#    #+#             */
/*   Updated: 2024/09/17 16:17:53 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	new_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	// if (x < 0)
	// 	return ;
	// else if (x >= S_W)
	// 	return ;
	// if (y < 0)
	// 	return ;
	// else if (y >= S_H)
	// 	return ;
	// is above better check?
	if (x < 0 || y < 0 || x >= S_W || y >= S_H)
		return ;
	mlx_put_pixel(mlx->img, x, y, color);
}

int	get_color()
{
	//(0, 255, 255) to 0x89CFF3FF type??
}

void	render_floor_ceiling(t_mlx *mlx, int ray, double t_pixel, double b_pixel)
{
	int	i;
	int	color;

	color = get_color(); //how??
	i = b_pixel;
	while (i < S_H)
		new_mlx_pixel_put(mlx, ray, i++, color); //floor
	i = 0;
	while (i < t_pixel)
		new_mlx_pixel_put(mlx, ray, i++, color); //ceiling
}

t_image	*get_texture(t_mlx *mlx, int wall_flag)
{
	mlx->ray->ray_angle = normalize_angle(mlx->ray->ray_angle);
	if (wall_flag == 0)
	{
		if (mlx->ray->ray_angle > M_PI / 2
			&& mlx->ray->ray_angle < 3 * (M_PI / 2))
			return (mlx->tex->ea_img);
		else
			return (mlx->tex->we_img);
	}
	else
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < M_PI)
			return (mlx->tex->so_img);
		else
			return (mlx->tex->no_img);
	}
	
}

void    render_walls(t_mlx *mlx, double t_pixel, double b_pixel, double wall_h)
{
	t_texture	*texture;
	int color = 0; // *fix for compile, what is color in (new_)mlx_pixel_put?

	texture = get_texture(mlx, mlx->ray->wall_flag);
	while (t_pixel < b_pixel)
	{
		new_mlx_pixel_put(mlx, mlx->ray->index, t_pixel, color); //parameters?? color?
		t_pixel++;
	}
}

void	rendering(t_mlx *mlx, int ray)
{
	double	wall_height;
	double	top_pixel;
	double	bottom_pixel;

	wall_height = (TILE_SIZE / mlx->ray->distance)
		* ((S_W / 2) / tan(mlx->ply->fov_radian / 2));
	top_pixel = (S_H / 2) - (wall_height / 2);
	bottom_pixel = (S_H / 2) + (wall_height / 2);
	if (top_pixel > S_H)
		top_pixel = S_H;
	if (bottom_pixel < 0)
		bottom_pixel = 0;
	render_walls(mlx, top_pixel, bottom_pixel, wall_height);
	render_floor_ceiling(mlx, ray, top_pixel, bottom_pixel);
}
