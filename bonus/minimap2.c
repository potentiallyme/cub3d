/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:59:41 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/11 18:00:35 by yu-chen          ###   ########.fr       */
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
			if (mm->nswe[dir][i * 16 + j] > 0){
				// printf("%i\n", mm->nswe[dir][i * 16 + j]);
				draw_pix(mm->img, x + j, y + i, mm->nswe[dir][i * 16 + j]);
			}
			j++;
		}
		i++;
	}
}

void	draw_nswe(t_minimap *mm, int x, int y)
{
	if (y == 0 && x == 4)
		set_nswe_tile(mm, 0, 64, 0);
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
	else if (mm->map[y][x] == 'D')
		set_mmap_tile(mm, x * mm->tile_size, y * mm->tile_size, mm->color_door);
	else if (mm->map[y][x] == ' ')
		set_mmap_tile(mm, x * mm->tile_size,
			y * mm->tile_size, mm->color_space);
	draw_nswe(mm, x, y);
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


void	render_mmap_img(t_mlx *mlx, t_image *img)
{
	// int	img_size;
	int	x;
	int	y;

	// img_size = PIXEL_SIZE + mm->tile_size;
	// img_do(mlx, &mlx->minimap, img_size, img_size);
	t_minimap	mm;

	mm.map = NULL;
	mm.img = img;
	mm.view_dist = VIEW_DIST;
	mm.tile_size = PIXEL_SIZE / (2 * mm.view_dist);
	mm.size = (2 * mm.view_dist) + 1;
	mm.off_x = get_mmap_off(&mm, S_W, (int)mlx->ply.ply_x);
	mm.off_y = get_mmap_off(&mm, S_H, (int)mlx->ply.ply_y);
	mm.map = create_map(mlx, &mm);
	if (!mm.map) {
        printf("Failed to create minimap\n");
        return;
    }
	mm.color_floor = 0xE6E6E6;
	mm.color_ply = 0xFF0000;
	mm.color_space = 0x404040;
	mm.color_wall = 0x808080;
	mm.color_door = 0xFF9300FF;
	mm.nswe = malloc(sizeof(int *) * 5);
	mm.nswe[0] = my_xpm_to_file(mlx, "./textures/north_mm.xpm", 16);
	mm.nswe[1] = my_xpm_to_file(mlx, "./textures/north_mm.xpm", 16);
	mm.nswe[2] = my_xpm_to_file(mlx, "./textures/north_mm.xpm", 16);
	mm.nswe[3] = my_xpm_to_file(mlx, "./textures/north_mm.xpm", 16);
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
