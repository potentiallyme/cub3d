/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:52:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/07 20:52:54 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


void draw_pix(t_image *img, int x, int y, int color)
{
	int pix;

	pix = y * (img->size_line / 4) + x;
	img->pixels[pix] = color;
}

// int	draw_map_pixel(void *ml) //new add
// {
// 	t_mlx	*mlx;
// 	t_image image;
// 	int x;
// 	int y = -1;

// 	mlx = ml;
// 	image.img = mlx_new_image(mlx->mlx_p, S_W, S_H);;
// 	img_set(mlx, &image, S_H, S_W);
// 	while (++y < S_H / 2)
// 	{
// 		x = -1;
// 		while (++x < S_W)
// 		{
// 			draw_pix(&image, x, y, get_color(ft_atoi(mlx->data->c_ceiling[0]), \
// 		ft_atoi(mlx->data->c_ceiling[1]), ft_atoi(mlx->data->c_ceiling[2])));
// 			draw_pix(&image, x, y + (S_H / 2), get_color(ft_atoi(mlx->data->c_floor[0]), \
// 		ft_atoi(mlx->data->c_floor[1]), ft_atoi(mlx->data->c_floor[2])));
// 		}
// 	}
// 	mlx_destroy_image(mlx->mlx_p, image.img);
// 	image.img = NULL;
// 	handle_ply_movement(mlx, 0, 0);
// 	// return 0;
// 	cast_rays(mlx);
// 	mlx_put_image_to_window(mlx->mlx_p, mlx->win, image.img, 0, 0);
// 	// mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->tex->no_img, 0, 0);
// 	return (1);
// }

// int check_for_tile(char **map, double xx, double yy, char c)
// {
// 	int x;
// 	int y;

// 	x = (int)xx;
// 	y = (int)yy;
// 	if (map[y][x] == c || map[y + 1][x])
// }

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
	mlx->ply.has_moved += move_player(mlx); //continue
	if (mlx->ply.has_moved == 0)
		return (0);
	check_actions(mlx);
	init_tex_pix(mlx);
	cast_rays(mlx);
	render_image(mlx);
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

void init_game(t_mlx *game, char **av)
{
	init_mlx(game);
	init_data(game, &game->data, av);	
	init_tex(&game->tex);
	init_ray(&game->ray);
	init_player(game, &game->ply);
	init_images(game);
	init_tex_pix(game);
}

void	cub_three_d(char **av)
{
	t_mlx	game;

	init_game(&game, av);
	cast_rays(&game);
	render_image(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game);
	mlx_loop_hook(game.mlx_p, loop_render, &game);
	mlx_loop(game.mlx_p);
	ft_exit(&game);
}

int	main(int ac, char **av)
{
	if ((ac != 2 || !is_cub(av[1])))
		return (ft_printf("Argument error: format: ./cub3d map.cub\n"), 0);
	cub_three_d(av);
	return (0);
}
