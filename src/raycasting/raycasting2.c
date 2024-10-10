/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:40:30 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/10 20:13:04 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// int is_valid_pos_collision(char **map, int x, int y)
// {
// 	if (map[y][x] > '0')
// 		return (FALSE);
// 	if (is_player(map[y][x]) == TRUE)
// 		return (TRUE);
// 	return (TRUE);
// }

int	is_valid_pos(t_data *data, double x, double y)
{
	int	ret;

	ret = TRUE;
	// printf("x %f, y %f\n", x, y);
	if (x <= 0.2 || x >= data->map_w - 1.2)
		return (FALSE);
	if (y <= 0.2 || y >= data->map_h - 1)
		return (FALSE);
	// if (BONUS)
	// is_valid_pos_collision(data->square_map, (int)x, (int)y);
	if (data->square_map[(int)y][(int)x] > '0')
		return (FALSE);
	if (is_player(data->square_map[(int)y][(int)x]) == TRUE)
		return (TRUE);
	return (TRUE);
}

int	*get_textures(t_ray *ray, t_tex *tex)
{
	int	*dir;

	dir = tex->no;
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			dir = tex->we;
		else
		{
			dir = tex->ea;
			// f = 1;
		}
	}
	else
	{
		if (ray->dir_y < 0)
		{
			dir = tex->no;
			// f = 1;
		}
		else
			dir = tex->so;
	}
	return (dir);
}

void	set_textures(t_mlx **mlx, t_tex *tex, t_ray *ray, int x)
{
	int	y;
	int	color;
	int	*dir;
	// int f =0;
	color = 0;
	dir = tex->no;
	dir = get_textures(ray, tex);
	// door func if ply->open == 1
	// check dir player is facing and from that dir check x/y +/- 2
	// if door exists (open or closed) act on it and change ply->open to 0
	tex->x = (int)(ray->wall_x * (*mlx)->img_size);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1
			&& ray->dir_y > 0))
		tex->x = (*mlx)->img_size - tex->x - 1;
	tex->step = 1.0 * (*mlx)->img_size / ray->line_height;
	tex->pos = (ray->draw_start - S_H / 2 + ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	// printf("y: %i, start: %i, end: %i\n", y, ray->draw_start, ray->draw_end);
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & ((*mlx)->img_size - 1);
		tex->pos += tex->step;
		color = dir[(*mlx)->img_size * tex->y + tex->x];
		// if (f == 1)
		// 	color = (color >> 1) & 8355711;
		if (color > 0)
			(*mlx)->tex_pix[y][x] = color;
		// printf("dir %x, texpix %x\n", dir[(*mlx)->img_size * tex->y + tex->x], (*mlx)->tex_pix[y][x]);
		y++;
	}
}
