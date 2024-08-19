/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:52:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/19 18:23:11 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	cub_three_d(char **av)
{
	t_data	*game;

	game = init_mlx();
	game->info = init_data(av);
	if (!game->info)
	{
		free_mlx(game, 1);
		ft_printf("errors\n");
	}
	else
		ft_printf("All good\n");
	return ;
	game->ray = init_ray();
	game->ply = init_player(game->info);
	if (!game || !game->info)
		return ;
}

int	main(int ac, char **av)
{
	if ((ac != 2 || !is_cub(av[1])))
		return (ft_printf("Argument error: format: ./cub3d map.cub\n"), 0);
	cub_three_d(av);
	return (0);
}