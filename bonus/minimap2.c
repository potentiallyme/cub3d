/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:59:41 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/09 15:04:36 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	set_mmap_tile(t_minimap *mm, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < mm->tile_size)
	{
		j = 0;
		while (j < mm->tile_size)
		{
			draw_pix(mm->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_mmap_tile(t_minimap *mm, int x, int y)
{
	if (mm->map[y][x] == 'P')
		set_mmap_tile(mm, x * mm->tile_size, y * mm->tile_size, mm->color_ply);
	else if (mm->map[y][x] == '1')
		set_mmap_tile(mm, x * mm->tile_size, y * mm->tile_size, mm->color_wall);
	else if (mm->map[y][x] == '0')
		set_mmap_tile(mm, x * mm->tile_size,
			y * mm->tile_size, mm->color_floor);
	else if (mm->map[y][x] == ' ')
		set_mmap_tile(mm, x * mm->tile_size,
			y * mm->tile_size, mm->color_space);
}

void	draw_border(t_minimap *mm, int color)
{
	int	size;
	int	x;
	int	y;

	size = PIXEL_SIZE + mm->tile_size;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x <= size)
		{
			if (x < 5 || x > size - 5 || y < 5 || y > size - 5)
				draw_pix(mm->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_mmap_img(t_mlx *mlx, t_minimap *mm)
{
	int	img_size;
	int	x;
	int	y;

	img_size = PIXEL_SIZE + mm->tile_size;
	img_do(mlx, &mlx->minimap, img_size, img_size);
	y = 0;
	while (y < mm->size)
	{
		x = 0;
		while (x < mm->size)
		{
			if (!mm->map[y] || !mm->map[y][x] || mm->map[y][x] == '\0')
				break ;
			draw_mmap_tile(mm, x, y);
			x++;
		}
		y++;
	}
	draw_border(mm, mm->color_space);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->minimap.img,
		mm->tile_size, S_H - (PIXEL_SIZE + mm->tile_size * 2));
	mlx_destroy_image(mlx->mlx_p, mlx->minimap.img);
}
