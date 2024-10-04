/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:45 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/03 21:15:19 by lmoran           ###   ########.fr       */
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

int	*get_texture(t_mlx *mlx, int wall_flag) //!
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
// 	factor = (double)mlx->img_size / wall_h;
// 	y_o = (t_pixel - (S_H / 2) + (wall_h / 2)) * factor;
// 	while (t_pixel < b_pixel)
// 	{
// 		new_mlx_pixel_put(mlx, mlx->ray->index, t_pixel, 0x000000FF);
// 		y_o += factor;
// 		t_pixel++;
// 	}
// 	(void)wall_h;
// 	(void)texture;
// 

double	get_x_o(t_mlx *mlx)//!
{
	double	x_o;

	if (mlx->ray->wall_flag == 1)
	{
		x_o = (int)fmodf((mlx->ray->horiz_x * \
		(mlx->img_size / TILE_SIZE)), mlx->img_size);
		printf("horiz_x: %f, mlx->img_size: %d, x_o:%f\n", mlx->ray->horiz_x, mlx->img_size, x_o);
	}
	else
	{
		x_o = (int)fmodf((mlx->ray->vert_y * \
		(mlx->img_size / TILE_SIZE)), mlx->img_size);
		printf("mlx->img_size: %d, x_o:%f\n", mlx->img_size, x_o);
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
void img_set(t_mlx *mlx, t_image *img, int height, int width)
{
	img->img = 0;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
	img->pixels = 0;
	img->instances = 0;

	img->img = mlx_new_image(mlx->mlx_p, width, height);
	if (!img->img)
		ft_exit(mlx); //! CHECK
	img->pixels = (int *)mlx_get_data_addr(img->img, &img->pixel_bits, \
	&img->size_line, &img->endian);
}

void render_wall(t_mlx *mlx, double t_pix, double b_pix, double wall_h)//!
{
	t_image img;
	int x;
	int y;

	img.img = NULL;
	img_set(mlx, &img, mlx->img_size, mlx->img_size);
	y = 0;
	while (++y < S_H / 2)
    {
        x = -1;
        while (++x < S_W)
        {
            draw_pix(&img, x, y, get_color(ft_atoi(mlx->data->c_ceiling[0]),
                ft_atoi(mlx->data->c_ceiling[1]), ft_atoi(mlx->data->c_ceiling[2])));
            draw_pix(&img, x, y + (S_H / 2), get_color(ft_atoi(mlx->data->c_floor[0]),
                ft_atoi(mlx->data->c_floor[1]), ft_atoi(mlx->data->c_floor[2])));
        }
    }
	y = 0;
	while (y < S_H)
	{
		x = 0;
		while (x < S_W)
		{
			draw_pix(&img, x, y, mlx->tex->no_img[y * (img.size_line / 4) + x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx_p, img.img);
	(void)b_pix;(void)t_pix;(void)wall_h;
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
