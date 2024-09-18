/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:52:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/18 16:18:57 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_map_pixel(void *ml) //new add
{
	t_mlx	*mlx;

	mlx = ml;
	mlx_destroy_image(mlx->mlx_p, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H);
	handle_ply_movement(mlx, 0, 0);
	cast_rays(mlx);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, 0, 0);
}

void	cub_three_d(char **av)
{
	t_mlx	*game;

	game = init_mlx();
	// ! Home pc can't run mlx, can't test if all inits worked but should work fine
	game->data = init_data(av);
	if (!game->data)
		free_mlx(game, 1);
	game->ray = init_ray();
	game->ply = init_player(game->data);
	if (!game || !game->data)
		return ;
	mlx_key_hook(game->win, &key_press, game);
	// mlx_loop_hook(mlx.mlx_ptr, &draw_map_pixel, &mlx); //?where is draw_map_pixel
	mlx_loop(game->mlx_p);
	ft_exit(mlx);
}

int	main(int ac, char **av)
{
	if ((ac != 2 || !is_cub(av[1])))
		return (ft_printf("Argument error: format: ./cub3d map.cub\n"), 0);
	cub_three_d(av);
	return (0);
}
