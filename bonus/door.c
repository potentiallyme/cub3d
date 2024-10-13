/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:09:10 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/13 15:46:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	render_door(t_mlx *mlx, t_image *img)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < S_H)
	{
		x = 0;
		while (x < S_W)
		{
			// if (mlx->ray.door == 1)
			if (mlx->data.square_map[mlx->ray.map_y][mlx->ray.map_x] == 'D')
			{
				int *dir = mlx->tex.door;
				int tex_x = (int)(mlx->ray.wall_x * mlx->img_size);
				if ((mlx->ray.side == 0 && mlx->ray.dir_x < 0) || (mlx->ray.side == 1 && mlx->ray.dir_y > 0))
					tex_x = mlx->img_size - tex_x - 1;
				double step = 1.0 * mlx->img_size / mlx->ray.line_height;
				double tex_pos = (mlx->ray.draw_start - S_H / 2 + mlx->ray.line_height / 2) * step;
				int tex_y = (int)tex_pos & (mlx->img_size - 1);
				color = dir[mlx->img_size * tex_y + tex_x];
				if (color > 0)
					draw_pix(img, x, y, color);
			}
			x++;
		}
		y++;
	}
}


void	init_door_pix(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->tex_pix)
		ft_free_tab((void **)mlx->tex_pix);
	mlx->tex_pix = ft_calloc(S_H + 1, sizeof * mlx->tex_pix);
	if (!mlx->tex_pix)
		ft_exit(mlx, "");
	while (i < S_H)
	{
		mlx->tex_pix[i] = ft_calloc(S_W + 1, sizeof * mlx->tex_pix[i]);
		if (!mlx->tex_pix[i])
			ft_exit(mlx);
		i++;
	}
}

int	valid_door_pos(t_mlx *mlx, t_data *data, double x, double y)
{
	// printf("x %f, y %f\n", x, y);
	if (x <= 0.2 || x >= data->map_w - 1.2)
		return (FALSE);
	if (y <= 0.2 || y >= data->map_h - 1)
		return (FALSE);
	if ((data->square_map[(int)y][(int)x + 1] == 'D'
		|| data->square_map[(int)y][(int)x - 1] == 'D'
		|| data->square_map[(int)y + 1][(int)x] == 'D'
		|| data->square_map[(int)y - 1][(int)x] == 'D'))
	{
		if (mlx->ply.door == 1)
			return (TRUE);
	}
	return (FALSE);
}

void	handle_door(t_mlx *mlx)
{
	double	x;
	double	y;

	x = mlx->ply.ply_x;
	y = mlx->ply.ply_y;
	if (valid_door_pos(mlx, &mlx->data, x, y) == TRUE)
	{
		if (mlx->data.square_map[(int)y][(int)x + 1] == 'D')
		{
			mlx->data.square_map[(int)y][(int)x + 1] = 'O';
		}
		else if (mlx->data.square_map[(int)y][(int)x + 1] == 'O')
		{
			mlx->data.square_map[(int)y][(int)x + 1] = 'D';
		}
		mlx->ply.door = 0;
	}
}

