/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:40:30 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/13 19:31:38 by lmoran           ###   ########.fr       */
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

// int	is_valid_pos(t_data *data, double x, double y)
// {
// 	// int	ret;

// 	// ret = TRUE;
// 	// printf("x %f, y %f\n", x, y);
// 	if (x <= 0.2 || x >= data->map_w - 1.2)
// 		return (FALSE);
// 	if (y <= 0.2 || y >= data->map_h - 1)
// 		return (FALSE);
// 	// if (BONUS)
// 	// is_valid_pos_collision(data->square_map, (int)x, (int)y);
// 	if (data->square_map[(int)y][(int)x] > '0')
// 		return (FALSE);
// 	if (is_player(data->square_map[(int)y][(int)x]) == TRUE)
// 		return (TRUE);
// 	return (TRUE);
// }

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

// void	set_textures(t_mlx **mlx, t_tex *tex, t_ray *ray, int x)
// {
// 	int	y;
// 	int	color;
// 	int	*dir;
// 	// int f =0;
// 	color = 0;
// 	dir = tex->no;
// 	// door func if ply->door == 1
// 	// check dir player is facing and from that dir check x/y +/- 2
// 	// if door exists (open or closed) act on it and change ply->door to 0
// 	// if ((*mlx)->data.square_map[ray->map_y][ray->map_x] == 'D')
// 	if (ray->door == 1)
// 	{
// 		dir = tex->door;
// 		// for(int i=0;i<10000;i++)
// 		// 	ft_printf("%d\n", dir[i]);
// 		if ((*mlx)->ply.door == 1)
// 			handle_door(*mlx);
// 	}
// 	else
// 		dir = get_textures(ray, tex);
// 	tex->x = (int)(ray->wall_x * (*mlx)->img_size);
// 	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1
// 			&& ray->dir_y > 0))
// 		tex->x = (*mlx)->img_size - tex->x - 1;
// 	tex->step = 1.0 * (*mlx)->img_size / ray->line_height;
// 	tex->pos = (ray->draw_start - S_H / 2 + ray->line_height / 2) * tex->step;
// 	y = ray->draw_start;
// 	// printf("y: %i, start: %i, end: %i\n", y, ray->draw_start, ray->draw_end);
// 	while (y < ray->draw_end)
// 	{
// 		tex->y = (int)tex->pos & ((*mlx)->img_size - 1);
// 		tex->pos += tex->step;
// 		color = dir[(*mlx)->img_size * tex->y + tex->x];
// 		// if (f == 1)
// 		// 	color = (color >> 1) & 8355711;
// 		if (color > 0)
// 			(*mlx)->tex_pix[y][x] = color;
// 		// printf("dir %x, texpix %x\n", dir[(*mlx)->img_size * tex->y + tex->x], (*mlx)->tex_pix[y][x]);
// 		y++;
// 	}
// }

void set_textures(t_mlx **mlx, t_tex *tex, t_ray *ray, int x) {
    int y;
    int color;
    int *dir;

    color = 0;
    dir = tex->no;  // Default to north texture

    // Handle door logic
    if (ray->door == 1) {
        dir = tex->door;
        if ((*mlx)->ply.door == 1) {
            handle_door(*mlx); // Custom function to manage door behavior
        }
    } else {
        dir = get_textures(ray, tex); // Get the wall texture
    }

    tex->x = (int)(ray->wall_x * (*mlx)->img_size);
    if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1 && ray->dir_y > 0)) {
        tex->x = (*mlx)->img_size - tex->x - 1; // Adjust texture x based on ray side
    }

    // Calculate texture position and step
    tex->step = (double)(*mlx)->img_size / ray->line_height; 
    tex->pos = (ray->draw_start - S_H / 2 + ray->line_height / 2) * tex->step;

    // Loop through the height of the wall
    y = ray->draw_start;
    while (y < ray->draw_end) {
        tex->y = (int)tex->pos & ((*mlx)->img_size - 1); // Calculate current texture y
        tex->pos += tex->step; // Increment texture position
        color = dir[(*mlx)->img_size * tex->y + tex->x]; // Get pixel color from texture

        // Only draw if the color is valid
        if (color > 0) {
            (*mlx)->tex_pix[y][x] = color;
        }
        y++;
    }
}

