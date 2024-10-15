/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/15 14:00:48 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_mlx(t_mlx *game)
{
	game->mlx_p = mlx_init();
	if (!game->mlx_p)
		ft_exit(game, "Mlx_init error", MLX, 1);
	game->win = mlx_new_window(game->mlx_p, S_W, S_H, "cub3D");
	if (!game->win)
		ft_exit(game, "Mlx_new_window error", MLX, 1);
	game->tex_pix = 0;
	game->ply_pix = 0;
	game->img_size = 64;
	game->ply_speed = 0.0125;
	game->rot_speed = 0.03;
	game->gun = 0;
	return ;
}

void	check_data(t_mlx *mlx, t_data *data)
{
	if (data->file)
		free(data->file);
	if (!data->linked_file)
		ft_exit(mlx, "Parsing error, make sure the map is valid", PARSER, 1);
	if (!data->map2d)
		ft_exit(mlx, "Parsing error, make sure the map is valid", PARSER, 1);
	if (!data->square_map)
		ft_exit(mlx, "Parsing error, make sure the map is valid", PARSER, 1);
}	

void	parser(t_mlx *mlx, t_data *data, char **av)
{
	int		fd;

	fd = open(av[1], O_RDWR);
	if (fd < 0)
	{
		close(fd);
		ft_exit(mlx, "File cannot be opened", MLX, 1);
	}
	data->file = return_gnl(fd);
	string_to_list(data);
	data->map2d = return_map(data);
	data->square_map = make_square_map(data, '1');
	check_data(mlx, data);
	if (check_file(data) != 4)
		ft_exit(mlx, "Parsing error, make sure the map is valid", PARSER, 1);
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
}
