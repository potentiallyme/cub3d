/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:52:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/19 18:30:49 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	draw_map_pixel(void *ml) //new add
{
	t_mlx	*mlx;

	mlx = ml;

	// if (mlx->img)
	// 	mlx_destroy_image(mlx->mlx_p, mlx->img);
	// mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H);
	handle_ply_movement(mlx, 0, 0);
	cast_rays(mlx);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->tex->no_img->img, 0, 0);
	return (1);
}

t_texture *init_tex()
{
	t_texture *tex;

	tex = malloc(sizeof(t_texture));
	tex->no_img = 0;
	tex->so_img = 0;
	tex->ea_img = 0;
	tex->we_img = 0;
	tex->no_img = malloc(sizeof(t_image));
	tex->so_img = malloc(sizeof(t_image));
	tex->ea_img = malloc(sizeof(t_image));
	tex->we_img = malloc(sizeof(t_image));
	tex->no_img->height = 512;
	tex->so_img->height = 512;
	tex->ea_img->height = 512;
	tex->we_img->height = 512;
	tex->no_img->width = 512;
	tex->so_img->width = 512;
	tex->ea_img->width = 512;
	tex->we_img->width = 512;
	tex->no_img->instances = malloc(sizeof(t_instance));
	tex->so_img->instances = malloc(sizeof(t_instance));
	tex->ea_img->instances = malloc(sizeof(t_instance));
	tex->we_img->instances = malloc(sizeof(t_instance));
	return (tex);
}

void	cub_three_d(char **av)
{
	t_mlx	*game;

	game = init_mlx();
	game->tex = init_tex();
	game->data = init_data(av);
	if (!game->data)
		free_mlx(game, 1);
	set_mlx_images(game);
	game->ray = init_ray();
	game->ply = init_player(game->data);
	if (!game || !game->data)
		return ;
	mlx_key_hook(game->win, &key_press, game);
	mlx_loop_hook(game->mlx_p, &draw_map_pixel, game);
	mlx_loop(game->mlx_p);
	ft_exit(game);
}

int	main(int ac, char **av)
{
	if ((ac != 2 || !is_cub(av[1])))
		return (ft_printf("Argument error: format: ./cub3d map.cub\n"), 0);
	cub_three_d(av);
	return (0);
}
