/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:52:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/14 13:20:25 by yu-chen          ###   ########.fr       */
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
	// if (mlx->door == 1 && mlx->ply.door < 30)
	// 	mlx->data.door += 1;
	// printf("%f, %f\n", mlx->ply.dir_x, mlx->ply.dir_y);
	// if (mlx->ply.use && check_for_tile(mlx->data.map2d, mlx->ply.ply_x, mlx->ply.ply_y, 'E') == TRUE)
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
	// if (BONUS)
	// render_minimap(mlx);
	return (1);
}

void	init_tex(t_tex *tex)
{
	tex->ply = 0;
	tex->fire = 0;
	tex->door = 0;
	tex->no = 0;
	tex->so = 0;
	tex->ea = 0;
	tex->we = 0;
	tex->dir = 0;
	tex->pos = 0;
	tex->step = 0;
	tex->x = 0;
	tex->y = 0;
}

void	init_tex_pix(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->tex_pix)
		ft_free_tab((void **)mlx->tex_pix);
	mlx->tex_pix = ft_calloc(S_H + 1, sizeof * mlx->tex_pix);
	if (!mlx->tex_pix)
		ft_exit(mlx);
	while (i < S_H)
	{
		mlx->tex_pix[i] = ft_calloc(S_W + 1, sizeof * mlx->tex_pix[i]);
		if (!mlx->tex_pix[i])
			ft_exit(mlx);
		i++;
	}
}
