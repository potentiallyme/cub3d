/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:40:30 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/15 12:29:00 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calc_line_height(t_ray *ray, t_player *ply)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(S_H / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + S_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + S_H / 2;
	if (ray->draw_end >= S_H)
		ray->draw_end = S_H - 1;
	if (ray->side == 0)
		ray->wall_x = ply->ply_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = ply->ply_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
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
			dir = tex->ea;
	}
	else
	{
		if (ray->dir_y < 0)
			dir = tex->no;
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

	color = 0;
	dir = tex->no;
	dir = get_textures(ray, tex);
	tex->x = (int)(ray->wall_x * (*mlx)->img_size);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1
			&& ray->dir_y > 0))
		tex->x = (*mlx)->img_size - tex->x - 1;
	tex->step = 1.0 * (*mlx)->img_size / ray->line_height;
	tex->pos = (ray->draw_start - S_H / 2 + ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & ((*mlx)->img_size - 1);
		tex->pos += tex->step;
		color = dir[(*mlx)->img_size * tex->y + tex->x];
		if (color > 0)
			(*mlx)->tex_pix[y][x] = color;
		y++;
	}
}

int	is_valid_pos_collision(char **map, int x, int y)
{
	if (map[y][x] > '0')
		return (FALSE);
	if (is_player(map[y][x]) == TRUE)
		return (TRUE);
	return (TRUE);
}

// int	is_valid_pos(t_data *data, double x, double y)
// {
// 	if (x <= 1.2 || x >= data->map_w - 2.2)
// 		return (FALSE);
// 	if (y <= 1.2 || y >= data->map_h - 1.2)
// 		return (FALSE);
// 	if (BONUS)
// 		is_valid_pos_collision(data->square_map, (int)x, (int)y);
// 	return (TRUE);
// }

int	is_valid_pos(t_data *data, double x, double y)
{
	if (x <= 1.2 || x >= data->map_w - 2.2)
		return (FALSE);
	if (y <= 1.2 || y >= data->map_h - 1.2)
		return (FALSE);
	// if (BONUS)
	// 	is_valid_pos_collision(data->square_map, (int)x, (int)y);
	if (BONUS && data->square_map[(int)y][(int)x] > '0')
		return (FALSE);
	if (is_player(data->square_map[(int)y][(int)x]) == TRUE)
		return (TRUE);
	return (TRUE);
}