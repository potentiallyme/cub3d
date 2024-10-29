/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:19:29 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/21 16:23:09 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	img_thing(t_mlx *mlx, t_image *img, char *path, int size)
{
	img->img = NULL;
	img->pixels = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
	img->img = mlx_xpm_file_to_image(mlx->mlx_p, path, &size, &size);
	if (!img->img)
		ft_exit(mlx, "Mlx_xpm_file_to_image error", XPM, 1);
	img->pixels = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->size_line, &img->endian);
	return ;
}

int	*my_xpm_to_file(t_mlx *game, char *path, int size)
{
	t_image	img;
	int		*buf;
	int		x;
	int		y;

	img_thing(game, &img, path, size);
	buf = (int *)malloc(sizeof(buf) * size * size);
	if (!buf)
	{
		mlx_destroy_image(game->mlx_p, img.img);
		ft_exit(game, "My_xpm_file_to_image error", XPM, 1);
	}
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			buf[y * size + x] = img.pixels[y * size + x];
			++x;
		}
		++y;
	}
	mlx_destroy_image(game->mlx_p, img.img);
	return (buf);
}

void	init_images(t_mlx *game)
{
	game->tex.ply = my_xpm_to_file(game, game->data.ply, 240);
	game->tex.fire = my_xpm_to_file(game, game->data.fire, 240);
	game->tex.no = my_xpm_to_file(game, game->data.north, game->img_size);
	game->tex.so = my_xpm_to_file(game, game->data.south, game->img_size);
	game->tex.ea = my_xpm_to_file(game, game->data.east, game->img_size);
	game->tex.we = my_xpm_to_file(game, game->data.west, game->img_size);
}
