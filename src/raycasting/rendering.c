/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:45 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/15 14:14:19 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	img_do(t_mlx *mlx, t_image *img, int h, int w)
{
	img->img = NULL;
	img->pixels = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
	img->img = mlx_new_image(mlx->mlx_p, w, h);
	if (!img->img)
		ft_exit(mlx, "Mlx_new_image rendering error", ALL, 1);
	img->pixels = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->size_line, &img->endian);
	return ;
}

void	set_frame_img_pixel(t_mlx *mlx, t_image *img, int x, int y)
{
	if (mlx->tex_pix[y][x] > 0)
		draw_pix(img, x, y, mlx->tex_pix[y][x]);
	else if (y < S_H / 2)
		draw_pix(img, x, y, mlx->data.ceiling);
	else if (y < S_H - 1)
		draw_pix(img, x, y, mlx->data.floor);
}

void	free_mm(t_mlx *mlx)
{
	if (&mlx->mm)
		ft_free_tab((void **)mlx->mm.map);
}

void	render_image(t_mlx *mlx)
{
	t_image	img;
	int		x;
	int		y;

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
	if (BONUS)
	{
		render_player(mlx, &img);
		render_mmap_img(mlx, &img);
	}
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx_p, img.img);
	free_mm(mlx);
}
