/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/03 22:02:55 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_player_pos(t_data *mlx) //! square_map? map2d? use square->crash
{
	int i;
	int j;
	int n;

	i = 0;
	n = 0;
	while (mlx->square_map[i])
	{
		j = 0;
		while (mlx->square_map[i][j])
		{
			if (is_player(mlx->square_map[i][j]))
			{
				mlx->p_x = j;
				mlx->p_y = i;
				n++;
			}
			if (n > 1)
				return (FAIL);
			j++;
		}
		i++;
	}
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
}

void init_data(t_mlx *mlx, t_data *data, char **av)
{
	int		fd;

	fd = open(av[1], O_RDWR);
	data->exit = 0;
	data->file = return_gnl(fd); // malloc
	data->linked_file = 0;
	string_to_list(data); // malloc
	data->map2d = return_map(data); // malloc
	data->square_map = make_square_map(data); // malloc
	data->floor = 0;
	data->ceiling = 0;
	if (check_file(data) != 6)
		return (free_during_init(mlx, data));
	ft_printf("%sINIT_DATA SUCCESS%s\n", green, rst);
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

// void	get_angle(t_mlx *game, t_player *ply)
// {
// 	char	c;

// 	c = game->data->map2d[game->data->p_y][game->data->p_x];
// 	if (c == 'N')
// 		ply->angle = 3 * M_PI / 2;
// 	else if (c == 'S')
// 		ply->angle = M_PI / 2;
// 	else if (c == 'E')
// 		ply->angle = 0;
// 	else if (c == 'W')
// 		ply->angle = M_PI;
// 	printf("get_angle>c: %c ply->angle: %f\n", c, ply->angle);
// 	ply->ply_x = (game->data->p_x * TILE_SIZE) + TILE_SIZE / 2;
// 	ply->ply_y = (game->data->p_y * TILE_SIZE) + TILE_SIZE / 2;
// 	ply->fov_radian = (FOV * M_PI / 180);
// }

void	init_player(t_player *ply)
{
	ply->dir = 0;
	ply->ply_x = 0;
	ply->ply_y = 0;
	ply->dir_x = 0;
	ply->dir_y = 0;
	ply->plane_x = 0;
	ply->plane_y = 0;
	ply->has_moved = 0;
	ply->move_x = 0;
	ply->move_y = 0;
	ply->rot = 0;
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
