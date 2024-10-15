/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:59:41 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/15 13:43:25 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

void	set_nswe_tile(t_minimap *mm, int dir, int x, int y)
{
	int	j;
	int	i;

	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			if (mm->nswe[dir][i * 16 + j] > 0)
			{
				draw_pix(mm->img, x + j, y + i, mm->nswe[dir][i * 16 + j]);
			}
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
	if (y == 0 && x == 4)
		set_nswe_tile(mm, 0, 64, 0);
}

void	init_minimap(t_mlx *mlx, t_minimap *mm, t_image *img)
{
	mm->map = NULL;
	mm->img = img;
	mm->view_dist = VIEW_DIST;
	mm->tile_size = PIXEL_SIZE / (2 * mm->view_dist);
	mm->size = (2 * mm->view_dist) + 1;
	mm->off_x = get_mmap_off(mm, S_W, (int)mlx->ply.ply_x);
	mm->off_y = get_mmap_off(mm, S_H, (int)mlx->ply.ply_y);
	mm->map = create_map(mlx, mm);
	if (!mm->map)
	{
		printf("Failed to create minimap\n");
		return ;
	}
	mm->color_floor = 0xE6E6E6;
	mm->color_ply = 0xFF0000;
	mm->color_space = 0x404040;
	mm->color_wall = 0x808080;
	mm->nswe = mlx->mm.nswe;
}

void	render_mmap_img(t_mlx *mlx, t_image *img)
{
	int			x;
	int			y;
	t_minimap	mm;

	init_minimap(mlx, &mm, img);
	mlx->mm = mm;
	if (!mm.map)
		return ;
	y = 0;
	while (y < mm.size)
	{
		x = 0;
		while (x < mm.size)
		{
			if (!mm.map[y] || !mm.map[y][x] || mm.map[y][x] == '\0')
				break ;
			draw_mmap_tile(&mm, x, y);
			x++;
		}
		y++;
	}
	draw_border(&mm, mm.color_space);
}
