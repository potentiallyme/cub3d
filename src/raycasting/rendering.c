/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:45 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/11 15:22:35 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void img_do(t_mlx *mlx, t_image *img, int h, int w)
{
	img->img = NULL;
	img->pixels = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
	img->img = mlx_new_image(mlx->mlx_p, w, h);
	if (!img->img)
		full_exit(mlx, "mlx_new_image error");
	img->pixels = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->size_line, &img->endian);
	return ;
}

void	set_frame_img_pixel(t_mlx *mlx,  t_image *img, int x, int y)
{
	if (mlx->tex_pix[y][x] > 0)
		draw_pix(img, x, y, mlx->tex_pix[y][x]);
	else if (y < S_H / 2)
		draw_pix(img, x, y, mlx->data.ceiling);
	else if (y < S_H - 1)
		draw_pix(img, x, y, mlx->data.floor);
			
}

void	render_image(t_mlx *mlx)
{
	t_image img;
	int x;
	int y;


	img.img = NULL;
	img_do(mlx, &img, S_H, S_W);
	y = 0;
	while (y < S_H)
	{
		x = 0;
		while (x < S_W)
		{
			set_frame_img_pixel(mlx, &img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx_p, img.img);
}
