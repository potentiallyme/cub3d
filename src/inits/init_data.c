/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/12 14:08:12 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_data	*init_mlx(void)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	// game->mlx = mlx_init(); // ! can't test
	// if (!game->mlx)
	// 	free_mlx(game, 1);
	// game->win = mlx_new_window(game->mlx, S_W, S_H, "cub3D");
	// if (!game->win)
	// 	free_mlx(game, 1);
	// set up mouse loop?
	// ? Temporary
	game->mlx = 0;
	game->win = 0;
	//
	game->ray = 0;
	game->info = 0;
	game->ply = 0;
	game->exit = 0;
	return (game);
}

void pr_str(t_file *f)
{
	t_file *tpm;
	
	tpm = f;
	while (tpm)
	{
		ft_printf("tpm->s: %s\n", tpm->s);
		tpm = tpm->next;
	}
}

t_info	*init_data(char **av)
{
	t_info	*data;
	int		fd;

	fd = open(av[1], O_RDWR);
	data = malloc(sizeof(t_info));
	data->exit = 0;
	data->file = return_gnl(fd);
	data->linked_file = 0;
	string_to_list(data);
	data->map2d = return_map(data);
	data->floor = malloc(sizeof(int) * 2);
	data->ceiling= malloc(sizeof(int) * 2);
	// ft_printf("file:\n%s\n", data->file);
	pr_str(data->linked_file);
	// ft_printf("map:\n");
	// ft_putstr_double(data->map2d);
	
	if (check_file(data) != 5)
		return (free_during_init(data));
	data->floor = 0;
	data->ceiling = 0;
	ft_printf("INIT_DATA SUCCESS");
	return (data);
}

t_ray	*init_ray(void)
{
	return (NULL);
}

t_player	*init_player(t_info *info)
{
	(void)info;
	return (NULL);
}
