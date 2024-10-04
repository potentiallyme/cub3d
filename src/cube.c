/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:52:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/03 22:01:56 by lmoran           ###   ########.fr       */
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

int draw_map_pixel(t_mlx *ml)
{
    cast_rays(ml);
    handle_ply_movement(ml, 0, 0);
    return (1);
}


void init_tex(t_tex *tex)
{
	tex->no = 0;
	tex->so = 0;
	tex->ea = 0;
	tex->we = 0;
}

void init_game(t_mlx *game, char **av)
{
	init_mlx(&game);
	init_data(game, &game->data, av);	
	init_tex(&game->tex);
	init_ray(&game->ray);
	init_player(&game->ply);
	init_images(&game);
}

void	cub_three_d(char **av)
{
	t_mlx	game;

	init_game(&game, av);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game);
	mlx_loop_hook(game.mlx_p, draw_map_pixel, &game);
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
