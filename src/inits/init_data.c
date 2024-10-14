/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/14 12:14:06 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_mlx(t_mlx *game)
{
	game->mlx_p = mlx_init();
	if (!game->mlx_p)
		free_mlx(game, 1);
	game->win = mlx_new_window(game->mlx_p, S_W, S_H, "cub3D");
	if (!game->win)
		free_mlx(game, 1);
	game->tex_pix = 0;
	game->ply_pix = 0;
	game->img_size = 64;
	game->ply_speed = 0.0125;
	game->rot_speed = 0.03;
	game->gun = 0;
	game->door = 0;
	// mlx_mouse_move(game->mlx_p, game->win, S_W / 2, S_H / 2);
	return ;
}

void	parser(t_mlx *mlx, t_data *data, char **av)
{
	int		fd;

	fd = open(av[1], O_RDWR);
	if (fd < 0)
	{
		ft_printf("%sERROR\nFILE DOESN'T EXIST/CAN'T BE OPENED!%s\n", RED_PR, RST);
		return ;
	}
	data->file = return_gnl(fd); // malloc
	data->linked_file = 0;
	string_to_list(data); // malloc
	pr_str(data->linked_file);
	data->map2d = return_map(data); // malloc
	data->square_map = make_square_map(data); // malloc
	if (check_file(data) != 4)
		return (free_during_init(mlx, data));
	ft_printf("%sINIT_DATA SUCCESS!%s\n", GREEN_PR, RST);
}

void	init_data(t_mlx *mlx, t_data *data, char **av)
{
	data->player_dir = 0;
	data->exit = 0;
	data->north = 0;
	data->south = 0;
	data->west = 0;
	data->east = 0;
	data->p_x = 0;
	data->p_y = 0;
	data->map_w = 0;
	data->map_h = 0;
	data->file = 0;
	data->map2d = 0;
	data->square_map = 0;
	data->floor = 0;
	data->ceiling = 0;
	data->c_floor = 0;
	data->c_ceiling = 0;
	data->linked_file = 0;
	data->ply = 0;
	data->fire = 0;
	data->door = 0;
	parser(mlx, data, av);
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->door = 0;
}
