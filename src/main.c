/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:14:33 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/15 13:47:57 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_mm(t_mlx *game)
{
	if (BONUS)
	{
		game->mm.nswe = malloc(sizeof(int *) * 1);
		game->mm.nswe[0] = my_xpm_to_file(game, "./textures/north_mm.xpm", 16);
		if (!game->mm.nswe || !game->mm.nswe[0])
			ft_exit(game, "Mlx_init error", MLX, 1);
	}
	else
		game->mm.nswe = 0;
	game->mm.map = 0;
	game->mm.img = 0;
	game->mm.size = 0;
	game->mm.off_x = 0;
	game->mm.off_y = 0;
	game->mm.view_dist = 0;
	game->mm.tile_size = 0;
	game->mm.color_ply = 0;
	game->mm.color_floor = 0;
	game->mm.color_wall = 0;
	game->mm.color_space = 0;
}

void	init_game(t_mlx *game, char **av)
{
	init_mlx(game);
	init_data(game, &game->data, av);
	init_tex(&game->tex);
	init_ray(&game->ray);
	init_player(game, &game->ply);
	init_images(game);
	init_tex_pix(game);
	init_mm(game);
}

void	cub_three_d(char **av)
{
	t_mlx	game;

	init_game(&game, av);
	cast_rays(&game);
	render_image(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask,
		key_release, &game);
	mlx_loop_hook(game.mlx_p, loop_render, &game);
	mlx_loop(game.mlx_p);
	ft_exit(&game, "Game ended successfully", ALL, 0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		pre_exit("Format must be ./cub3D maps/map_name.cub", -1);
	if (!is_cub(av[1]))
		pre_exit("Make sure the input map file is .cub", -1);
	cub_three_d(av);
	return (0);
}
