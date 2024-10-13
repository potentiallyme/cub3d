/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:14:33 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/13 15:36:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_game(t_mlx *game, char **av)
{
	init_mlx(game);
	init_data(game, &game->data, av);
	init_tex(&game->tex);
	init_ray(&game->ray);
	init_player(game, &game->ply);
	init_images(game);
	init_tex_pix(game);
	// init_door_pix(game);
}

void	cub_three_d(char **av)
{
	t_mlx	game;

	init_game(&game, av);
	cast_rays(&game);
	render_image(&game);
	// render_minimap(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game);
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
