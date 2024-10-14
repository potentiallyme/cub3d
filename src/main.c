/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:14:33 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/14 12:51:57 by yu-chen          ###   ########.fr       */
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
	// mlx_hook(game.win, MotionNotify, PointerMotionMask, mouse_move, &game); //mcom way
	// mlx_loop_hook(game.mlx_p, mouse_move, &game);
	mlx_loop_hook(game.mlx_p, loop_render, &game);
	mlx_loop(game.mlx_p);
	ft_exit(&game);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("%sARGUMENT ERROR: format: ./cub3d map.cub%s\n", RED_PR, RST);
		return (-1);
	}
	if (!is_cub(av[1]))
	{
		ft_printf("%sERROR\nFILE SHOULD BE .cub!\n", RED_PR, RST);
		return (-1);
	}
	fd = open(av[1], O_RDWR);
	if (fd < 0)
	{
		ft_printf("%sERROR\nFILE DOESN'T EXIST/CAN'T BE OPENED!%s\n" \
			, RED_PR, RST);
		return (-1);
	}
	cub_three_d(av);
	return (0);
}
