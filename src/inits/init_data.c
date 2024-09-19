/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/19 18:28:57 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_player_pos(t_data *mlx) //new add
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map2d[i])
	{
		j = 0;
		while (mlx->map2d[i][j])
		{
			if (mlx->map2d[i][j] == 'N' || mlx->map2d[i][j] == 'S'
				|| mlx->map2d[i][j] == 'W' || mlx->map2d[i][j] == 'E')
			{
				mlx->p_x = j;
				mlx->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
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
	// set up mouse loop?
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
	data->ceiling = malloc(sizeof(int) * 2);
	if (check_file(data) != 6)
		return (free_during_init(data));
	data->p_x = 0; // find player char then send to init_player
	data->p_y = 0;
	ft_printf("INIT_DATA SUCCESS\n");
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

t_player	*init_player(t_data *data)
{
	t_player	*ply;

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

void	set_mlx_images(t_mlx *game)
{
	t_texture *tx;
	
	tx = game->tex;
	tx->no_img->img = mlx_xpm_file_to_image(game->mlx_p, game->data->north,&(tx->no_img->width),&(tx->no_img->height));
	if (!tx->no_img->img)
		ft_exit(game);
	tx->so_img->img = mlx_xpm_file_to_image(game->mlx_p, game->data->south,&(tx->so_img->width),&(tx->so_img->height));
	if (!tx->so_img->img)
		ft_exit(game);
	tx->ea_img->img = mlx_xpm_file_to_image(game->mlx_p, game->data->east,&(tx->ea_img->width),&(tx->ea_img->height));
	if (!tx->ea_img->img)
		ft_exit(game);
	tx->we_img->img = mlx_xpm_file_to_image(game->mlx_p, game->data->west,&(tx->we_img->width),&(tx->we_img->height));
	if (!tx->we_img->img)
		ft_exit(game);
}
