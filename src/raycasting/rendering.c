/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:45 by yu-chen           #+#    #+#             */
/*   Updated: 2024/09/19 16:57:29 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	new_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= S_W || y >= S_H)
		return ;
	mlx_pixel_put(mlx->mlx_p, mlx->win, x, y, color);
}

int	get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

void	render_floor_ceiling(t_mlx *mlx, int ray, double t_pixel, double b_pixel)
{
	int	i;
	char **floor_color;
	char **ceiling_color;

	// color = get_color();
	i = b_pixel;
	floor_color = mlx->data->c_floor; // *int = [244,54,12]
	while (i < S_H)
		new_mlx_pixel_put(mlx, ray, i++, get_color(ft_atoi(floor_color[0]), ft_atoi(floor_color[1]), ft_atoi(floor_color[2]), 255));
	i = 0;
	ceiling_color = mlx->data->c_ceiling;
	while (i < t_pixel)
		new_mlx_pixel_put(mlx, ray, i++, get_color(ft_atoi(ceiling_color[0]), ft_atoi(ceiling_color[1]), ft_atoi(ceiling_color[2]), 255));

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
	t_image	*texture;

	texture = get_texture(mlx, mlx->ray->wall_flag);
	while (t_pixel < b_pixel)
	{
		new_mlx_pixel_put(mlx, mlx->ray->index, t_pixel, 0x000000FF); //parameters?? color?
		t_pixel++;
	}
	(void)wall_h;
	(void)texture;
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
