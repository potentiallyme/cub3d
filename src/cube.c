/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:52:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/11 17:05:42 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


void draw_pix(t_image *img, int x, int y, int color)
{
	int pix;

	pix = y * (img->size_line / 4) + x;
	img->pixels[pix] = color;
}

void check_actions(t_mlx *mlx)
{
	if (mlx->ply.sprint == 0 && mlx->ply.gauge <= 100)
		mlx->ply.gauge += 0.05;
	if (mlx->ply.sprint == 1 && mlx->ply.gauge > 0)
		mlx->ply.gauge -= 0.125;
	if (mlx->ply.gauge <= 0)
		set_walk_speed(mlx, WALK);
	// printf("%f, %f\n", mlx->ply.dir_x, mlx->ply.dir_y);
	// if (mlx->ply.use && check_for_tile(mlx->data.map2d, mlx->ply.ply_x, mlx->ply.ply_y, 'E') == TRUE)
}

int loop_render(t_mlx *mlx)
{
	// ? check for player move, if not return
	// check for garbage freed
	mlx->ply.has_moved += move_player(mlx); //continue
	if (mlx->ply.has_moved == 0)
		return (0);
	check_actions(mlx);
	init_tex_pix(mlx);
	cast_rays(mlx);
	render_image(mlx);
	// if (BONUS)
	// 	render_minimap(mlx);
    return (1);
}


void init_tex(t_tex *tex)
{
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

void init_tex_pix(t_mlx *mlx)
{
	int i;
	
	i = 0;
	if (mlx->tex_pix)
		ft_free_any((void **)mlx->tex_pix);
	mlx->tex_pix = my_malloc(&mlx->garbage, S_H + 1, sizeof * mlx->tex_pix, DOUBLE);
	while (i < S_H)
	{
		mlx->tex_pix[i] = malloc((S_W + 1) * sizeof * mlx->tex_pix[i]);
		i++;
	}
}

void init_garbo(t_mlx *game)
{
	t_garbage *garbo;
	int garbage_freed;

	garbage_freed = 0;
	garbo = ft_calloc(sizeof * garbo, 1);
	garbo->garbage_freed = &garbage_freed;
	game->garbage = garbo;
	game->data.garbage = garbo;
	game->tex.garbage = garbo;
	game->garbage_freed = garbo->garbage_freed;
}

void init_game(t_mlx *game, int fd)
{
	init_garbo(game);
	init_mlx(game);
	init_data(game, &game->data, fd);	
	init_tex(&game->tex);
	init_ray(&game->ray);
	init_player(game, &game->ply);
	init_images(game);
	init_tex_pix(game);
	if (*game->garbage_freed == 1)
		full_exit(game, "init errors");
}

void	cub_three_d(char **av)
{
	t_mlx	game;
	int fd;

	fd = open(av[1], O_RDWR);
	if (fd < 1)
	{
		close(fd);
		ft_exit(&game);
	}
	init_game(&game, fd);
	cast_rays(&game);
	render_image(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game);
	mlx_loop_hook(game.mlx_p, loop_render, &game);
	mlx_loop(game.mlx_p);
	full_exit(&game, "Game finished");
}

int	main(int ac, char **av)
{
	if ((ac != 2 || !is_cub(av[1])))
		return (ft_printf("Argument error: format: ./cub3d map.cub\n"), 0);
	cub_three_d(av);
	return (0);
}
