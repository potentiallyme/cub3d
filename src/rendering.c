/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:48:45 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/21 17:18:40 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	render_floor_ceiling(t_mlx *mlx)
{
	
}

t_texture	*get_texture(t_mlx *mlx)
{
	
}

void    render_walls()
{
	t_texture	*texture;

	texture = get_texture();

}

void	rendering(t_mlx *mlx, int ray)
{
	double	wall_height;
	double	wall_top;
	double	wall_bottom;

	wall_height = (TILE_SIZE / mlx->ray->distance)
		* ((S_W / 2) / tan(mlx->ply->fov_radiant / 2));
	wall_top = (S_H / 2) - (wall_height / 2);
	wall_bottom = (S_H / 2) + (wall_height / 2);
	if (wall_top > S_H)
		wall_top = S_H;
	if (wall_bottom < 0)
		wall_bottom = 0;
	render_walls();
	render_floor_ceiling();
}
