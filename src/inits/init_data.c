/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/03 15:56:54 by lmoran           ###   ########.fr       */
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

t_mlx	*init_mlx(void)
{
	t_mlx	*game;

	game = malloc(sizeof(t_mlx));
	game->mlx_p = mlx_init();
	if (!game->mlx_p)
		free_mlx(game, 1);
	game->win = mlx_new_window(game->mlx_p, S_W, S_H, "cub3D");
	if (!game->win)
		free_mlx(game, 1);
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
	data->square_map = make_square_map(data);
	data->floor = malloc(sizeof(int) * 2);
	data->ceiling = malloc(sizeof(int) * 2);
	if (check_file(data) != 6)
		return (free_during_init(data));
	ft_printf("%sINIT_DATA SUCCESS%s\n", green, rst);
	return (data);
}

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->distance = 0;
	ray->index = 0;
	ray->ray_angle = 0;
	ray->wall_flag = 0;
	return (ray);
}

void	get_angle(t_mlx *game, t_player *ply)
{
	char	c;

	c = game->data->map2d[game->data->p_y][game->data->p_x];
	if (c == 'N')
		ply->angle = 3 * M_PI / 2;
	else if (c == 'S')
		ply->angle = M_PI / 2;
	else if (c == 'E')
		ply->angle = 0;
	else if (c == 'W')
		ply->angle = M_PI;
	printf("get_angle>c: %c ply->angle: %f\n", c, ply->angle);
	ply->ply_x = (game->data->p_x * TILE_SIZE) + TILE_SIZE / 2;
	ply->ply_y = (game->data->p_y * TILE_SIZE) + TILE_SIZE / 2;
	ply->fov_radian = (FOV * M_PI / 180);
}

t_player	*init_player(t_mlx *game)
{
	t_player	*ply;

	ply = malloc(sizeof(t_player));
	if (!ply)
		return (NULL);
	ply->fov_radian = 0;
	ply->l_r = 0;
	if (get_player_pos(game->data) == FAIL)
	{
		free(ply);
		return (NULL);
	}
	get_angle(game, ply);
	printf("init_player>ply->angle: %f\n", ply->angle);
	ply->rot = 0;
	ply->u_d = 0;
	return (ply);
}

void	set_mlx_pixels(t_texture *tx) //! not used
{
	tx->no_img->pixels = (int *)mlx_get_data_addr(tx->no_img->img,
			&tx->no_img->pixel_bits, &tx->no_img->size_line,
			&tx->no_img->endian);

	tx->so_img->pixels = (int *)mlx_get_data_addr(tx->so_img->img,
			&tx->so_img->pixel_bits, &tx->so_img->size_line,
			&tx->so_img->endian);

	tx->ea_img->pixels = (int *)mlx_get_data_addr(tx->ea_img->img,
			&tx->ea_img->pixel_bits, &tx->ea_img->size_line,
			&tx->ea_img->endian);

	tx->we_img->pixels = (int *)mlx_get_data_addr(tx->we_img->img,
			&tx->we_img->pixel_bits, &tx->we_img->size_line,
			&tx->we_img->endian);
}

void	set_mlx_images(t_mlx *game)
{
	t_texture	*tx;

	tx = game->tex;
	tx->no_img->img = mlx_xpm_file_to_image(game->mlx_p, game->data->north,
			&(tx->no_img->width), &(tx->no_img->height));
	if (!tx->no_img->img){
		printf("here\n");
		ft_exit(game);
	}
	tx->no_img->pixels = (int *)mlx_get_data_addr(tx->no_img->img,
			&(tx->no_img->pixel_bits), &(tx->no_img->size_line),
			&(tx->no_img->endian));
	tx->so_img->img = mlx_xpm_file_to_image(game->mlx_p, game->data->south,
			&(tx->so_img->width), &(tx->so_img->height));
	if (!tx->so_img->img)
		ft_exit(game);
	tx->so_img->pixels = (int *)mlx_get_data_addr(tx->so_img->img,
			&(tx->so_img->pixel_bits), &(tx->so_img->size_line),
			&(tx->so_img->endian));
	tx->ea_img->img = mlx_xpm_file_to_image(game->mlx_p, game->data->east,
			&(tx->ea_img->width), &(tx->ea_img->height));
	if (!tx->ea_img->img)
		ft_exit(game);
	tx->ea_img->pixels = (int *)mlx_get_data_addr(tx->ea_img->img,
			&(tx->ea_img->pixel_bits), &(tx->ea_img->size_line),
			&(tx->ea_img->endian));
	tx->we_img->img = mlx_xpm_file_to_image(game->mlx_p, game->data->west,
			&(tx->we_img->width), &(tx->we_img->height));
	if (!tx->we_img->img)
		ft_exit(game);
	tx->we_img->pixels = (int *)mlx_get_data_addr(tx->we_img->img,
			&(tx->we_img->pixel_bits), &(tx->we_img->size_line),
			&(tx->we_img->endian));
}
