/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/07 21:32:12 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void set_player(t_data *data, char c)
{
	if (c == 'N')
		data->player_dir = NO;
	else if (c == 'S')
		data->player_dir = SO;
	else if (c == 'W')
		data->player_dir = WE;
	else if (c == 'E')
		data->player_dir = EA;
}

int	get_player_pos(t_data *data)
{
	int i;
	int j;
	int n;

	i = 0;
	n = 0;
	while (data->map2d[i])
	{
		j = 0;
		while (data->map2d[i][j])
		{
			if (is_player(data->map2d[i][j]))
			{
				data->p_x = j;
				data->p_y = i;
				set_player(data, data->map2d[i][j]);
				data->map2d[i][j] = '0';
				n++;
			}
			j++;
		}
		i++;
	}
	if (n != 1)
		return (FAIL);
	return (SUCCESS);
}

void init_mlx(t_mlx *game)
{
	game->mlx_p = mlx_init();
	if (!game->mlx_p)
		free_mlx(game, 1);
	game->win = mlx_new_window(game->mlx_p, S_W, S_H, "cub3D");
	if (!game->win)
		free_mlx(game, 1);
	game->img_size = 64;
	game->ply_speed = 0.0125;
	game->rot_speed = 0.03;
}

void parser(t_mlx *mlx, t_data *data, char **av)
{
	int		fd;
	
	fd = open(av[1], O_RDWR);
	data->file = return_gnl(fd); // malloc
	string_to_list(data); // malloc
	pr_str(data->linked_file);
	data->map2d = return_map(data); // malloc
	// data->square_map = make_square_map(data); // malloc
	if (check_file(data) != 4)
		return (free_during_init(mlx, data));
	ft_printf("%sINIT_DATA SUCCESS%s\n", green, rst);
}

void init_data(t_mlx *mlx, t_data *data, char **av)
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
	parser(mlx, data, av);
}

void init_ray(t_ray *ray)
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

void set_player_cam(t_player **ply)
{
	// printf("%i\n", ply->nswe);
	if ((*ply)->nswe == SO)
	{
		(*ply)->dir_y = -1;
		(*ply)->plane_x = 0.66;
	}
	else if ((*ply)->nswe == EA)
	{
		(*ply)->dir_x = 1;
		(*ply)->plane_y = 0.66;
	}
	else if ((*ply)->nswe == WE)
	{
		(*ply)->dir_x = -1;
		(*ply)->plane_y = -0.66;
	}
}

void	init_player(t_mlx *mlx, t_player *ply)
{
	if (get_player_pos(&mlx->data) == FAIL)
	{	ft_printf("fail\n");
		ft_exit(mlx) ;}
	ply->ply_x = mlx->data.p_x;
	ply->ply_y = mlx->data.p_y;
	ply->nswe = mlx->data.player_dir;
	ply->dir_x = 0;
	ply->dir_y = 1;
	ply->plane_x = -0.66;
	ply->plane_y = 0;
	set_player_cam(&ply);
	ply->has_moved = 0;
	ply->move_x = 0;
	ply->move_y = 0;
	ply->rot_r = 0;
	ply->rot_l = 0;
	ply->sprint = 0;
	ply->gauge = 100;
	ply->use = 0;
}

void img_thing(t_mlx *mlx, t_image *img, char *path)
{
	img->img = NULL;
	img->pixels = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
	img->img = mlx_xpm_file_to_image(mlx->mlx_p, path, &mlx->img_size, &mlx->img_size);
	if (!img->img)
		ft_exit(mlx);
	img->pixels = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->size_line, &img->endian);
	return ;
}

int *my_xpm_to_file(t_mlx *game, char *path)
{
	t_image img;
	int *buf;
	int x;
	int y;

	img_thing(game, &img, path);
	buf = ft_calloc(1, sizeof * buf * game->img_size * game->img_size);
	if (!buf)
		ft_exit(game); // ! CHECK
	y = 0;
	while (y < game->img_size)
	{
		x = 0;
		while (x < game->img_size)
		{
			buf[y * game->img_size + x] = img.pixels[y * game->img_size + x];
			++x;
		}
		++y;
	}
	mlx_destroy_image(game->mlx_p, img.img);
	return (buf);
}

void	init_images(t_mlx *game)
{
	game->tex.no = my_xpm_to_file(game, game->data.north);
	game->tex.so = my_xpm_to_file(game, game->data.south);
	game->tex.ea = my_xpm_to_file(game, game->data.east);
	game->tex.we = my_xpm_to_file(game, game->data.west);
}
