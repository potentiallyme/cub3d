/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/17 16:01:59 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_mlx	*init_mlx(void)
{
	t_mlx	*game;

	game = malloc(sizeof(t_mlx));
	// game->mlx_p = mlx_init(); // ! can't test at home
	// if (!game->mlx)
	// 	free_mlx(game, 1);
	// game->win = mlx_new_window(game->mlx, S_W, S_H, "cub3D");
	// if (!game->win)
	// 	free_mlx(game, 1);
	// set up mouse loop?
	// ? Temporary
	game->mlx_p = 0;
	game->win = 0;
	//
	game->ray = 0;
	game->ply = 0;
	return (game);
}

t_data	*init_data(char **av)
{
	t_data	*data;
	int		fd;

	fd = open(av[1], O_RDWR);
	data = malloc(sizeof(t_data));
	data->exit = 0;
	data->file = return_gnl(fd);
	data->linked_file = 0;
	string_to_list(data);
	data->map2d = return_map(data);
	data->floor = malloc(sizeof(int) * 2);
	data->ceiling= malloc(sizeof(int) * 2);
	if (check_file(data) != 6)
		return (free_during_init(data));
	data->floor = 0;
	data->ceiling = 0;
	data->p_x = 0; // find player char then send to init_player
	data->p_y = 0;
	ft_printf("INIT_DATA SUCCESS");
	return (data);
}

t_ray	*init_ray(void)
{
	return (NULL);
}

t_player	*init_player(t_data *data)
{
	t_player *ply;

	ply = malloc(sizeof(t_player));
	ply->angle = 0;
	ply->fov_radian = 0;
	ply->l_r = 0;
	ply->ply_x = data->p_x; // ? NEED IN PARSING (FIND PLAYER CHAR)
	ply->ply_y = data->p_y;
	ply->rot = 0;
	ply->u_d = 0;
	return (ply);
}
