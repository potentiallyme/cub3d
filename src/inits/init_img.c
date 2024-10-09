/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:19:29 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/09 14:27:16 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	img_thing(t_mlx *mlx, t_image *img, char *path)
{
	img->img = NULL;
	img->pixels = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
	img->img = mlx_xpm_file_to_image(mlx->mlx_p, path \
			, &mlx->img_size, &mlx->img_size);
	if (!img->img)
		ft_exit(mlx);
	img->pixels = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->size_line, &img->endian);
	return ;
}

int	*my_xpm_to_file(t_mlx *game, char *path)
{
	t_image	img;
	int		*buf;
	int		x;
	int		y;

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
