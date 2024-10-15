/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:52:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/15 14:34:02 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_pix(t_image *img, int x, int y, int color)
{
	int	pix;

	if (x < 0 || x >= S_W || y < 0 || y >= S_H)
		return ;
	pix = y * (img->size_line / 4) + x;
	img->pixels[pix] = color;
}

void	static_sync(t_mlx *game, int interval)
{
	mlx_do_sync(game->mlx_p);
	usleep(interval);
}

void	check_actions(t_mlx *mlx)
{
	if (mlx->ply.sprint == 0 && mlx->ply.gauge <= 100)
		mlx->ply.gauge += 0.05;
	if (mlx->ply.sprint == 1 && mlx->ply.gauge > 0)
		mlx->ply.gauge -= 0.125;
	if (mlx->ply.gauge <= 0)
		set_walk_speed(mlx, WALK);
}

int	loop_render(t_mlx *mlx)
{
	if (BONUS)
		mouse_move(mlx);
	mlx->ply.has_moved += move_player(mlx);
	if (mlx->ply.has_moved == 0)
		return (0);
	check_actions(mlx);
	init_tex_pix(mlx);
	cast_rays(mlx);
	render_image(mlx);
	return (1);
}
