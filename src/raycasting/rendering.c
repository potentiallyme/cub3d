/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:45 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/03 15:25:09 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	new_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0)
		return ;
	else if (y >= S_H)
		return ;
	mlx_pixel_put(mlx->mlx_p, mlx->win, x, y, color);
}

int	get_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b << 0);
}

void	render_floor_ceiling(t_mlx *mlx, int ray, double t_pixel, double b_pixel)
{
	int		i;
	char	**floor_color;
	char	**ceiling_color;

	i = b_pixel;
	floor_color = mlx->data->c_floor;
	while (i < S_H)
		new_mlx_pixel_put(mlx, ray, i++, get_color(ft_atoi(floor_color[0]), \
		ft_atoi(floor_color[1]), ft_atoi(floor_color[2])));
	i = 0;
	ceiling_color = mlx->data->c_ceiling;
	while (i < t_pixel)
		new_mlx_pixel_put(mlx, ray, i++, get_color(ft_atoi(ceiling_color[0]), \
		ft_atoi(ceiling_color[1]), ft_atoi(ceiling_color[2])));

}

t_image	*get_texture(t_mlx *mlx, int wall_flag) //!
{
	printf("get_texture>ray_angle:%f\n", mlx->ray->ray_angle);
	mlx->ray->ray_angle = normalize_angle(mlx->ray->ray_angle);
	printf("get_texture>ray_angle:%f\n", mlx->ray->ray_angle);
	if (wall_flag == 0)
	{
		if (mlx->ray->ray_angle > M_PI / 2
			&& mlx->ray->ray_angle < 3 * (M_PI / 2))
			return (mlx->tex->ea_img); //new add ""
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
	return (mlx->tex->no_img);
}

// void    render_walls(t_mlx *mlx, double t_pixel, double b_pixel, double wall_h)
// {
// 	double	y_o;
// 	t_image	*texture;
// 	double	factor;

// 	texture = get_texture(mlx, mlx->ray->wall_flag);
// 	factor = (double)texture->height / wall_h;
// 	y_o = (t_pixel - (S_H / 2) + (wall_h / 2)) * factor;
// 	while (t_pixel < b_pixel)
// 	{
// 		new_mlx_pixel_put(mlx, mlx->ray->index, t_pixel, 0x000000FF);
// 		y_o += factor;
// 		t_pixel++;
// 	}
// 	(void)wall_h;
// 	(void)texture;
// }

int	reverse_bytes(int c)//!
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

double	get_x_o(t_image	*texture, t_mlx *mlx)//!
{
	double	x_o;

	if (mlx->ray->wall_flag == 1)
	{
		x_o = (int)fmodf((mlx->ray->horiz_x * \
		(texture->width / TILE_SIZE)), texture->width);
		printf("horiz_x: %f, texture->width: %d, x_o:%f\n", mlx->ray->horiz_x, texture->width, x_o);
	}
	else
	{
		x_o = (int)fmodf((mlx->ray->vert_y * \
		(texture->width / TILE_SIZE)), texture->width);
		printf("texture->width: %d, x_o:%f\n", texture->width, x_o);
	}
	return (x_o);

}

// void init_img(t_img *img)
// {
// 	img->img = NULL;
// 	img->pixels = NULL
// }

// void render_wall_2(t_mlx *mlx, double t_pix, double b_pix, double w_h)
// {
// 	t_image img;
// 	int x;
// 	int y;
	
// 	img.img = NULL;
// 	init_img(img);
// }

void render_wall(t_mlx *mlx, double t_pix, double b_pix, double wall_h)//!
{
    double x_o;
    double y_o;
    t_image *texture;
    uint32_t *arr;
    double factor;
	
    texture = get_texture(mlx, mlx->ray->wall_flag);
    if (!texture)
        return ;
    arr = (uint32_t *)texture->pixels;
    factor = (double)texture->height / wall_h;
    x_o = get_x_o(texture, mlx);
    y_o = (t_pix - (S_H / 2) + (wall_h / 2)) * factor;
	printf("factor = texture->height %d / wall_h%f: x_o: %f, y_o: %f\n\n", texture->height, wall_h, x_o, y_o);
    if (y_o < 0)
		y_o = 0;
    while (t_pix < b_pix)
    {
		new_mlx_pixel_put(mlx, mlx->ray->index, t_pix, reverse_bytes \
		(arr[(int)y_o * texture->width + (int)x_o])); //!
        // draw_pix(texture, mlx->ray->index, t_pix, 0xFF00FF);
		y_o += factor;
        t_pix++;
    }
}


void	rendering(t_mlx *mlx, int ray)
{
	double	wall_height;
	double	top_pixel;
	double	bottom_pixel;
	// printf("dst: %lf\n", (TILE_SIZE / mlx->ray->distance)* (S_W / 2) /tan(mlx->ply->fov_radian)/2);

	mlx->ray->distance *= cos(normalize_angle(mlx->ray->ray_angle - mlx->ply->angle));
	printf("rendering>distance: %lf\n", mlx->ray->distance);
	wall_height = (TILE_SIZE / mlx->ray->distance)
		* ((S_W / 2) / tan(mlx->ply->fov_radian / 2));
	printf("wall_height: %lf\n", wall_height);
	bottom_pixel = (S_H / 2) + (wall_height / 2);
	top_pixel = (S_H / 2) - (wall_height / 2);
	if (bottom_pixel > S_H) //was worongly put with top_pixel
		bottom_pixel = S_H;
	if (top_pixel < 0) //was worongly put with bottom_pixel
		top_pixel = 0;
	mlx->ray->index = ray;
	printf("rendering>index: %d\n", mlx->ray->index);
	printf("t: %f, b: %f, w: %f\n", top_pixel, bottom_pixel, wall_height);
	render_wall(mlx, top_pixel, bottom_pixel, wall_height);
	render_floor_ceiling(mlx, ray, top_pixel, bottom_pixel);
}
