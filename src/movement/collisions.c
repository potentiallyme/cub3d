/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:30:37 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/27 22:18:54 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	wall_hit(t_mlx *mlx, double x, double y)
{
	int	maply_x;
	int	maply_y;
	
	if (x < 0 || y < 0)
		return (FALSE); //over the map
	maply_x = floor (x / TILE_SIZE);
	maply_y = floor (y / TILE_SIZE);
	if (maply_x >= mlx->data->map_w || maply_y >= mlx->data->map_h)
		return (FALSE);
	if (mlx->data->map2d[maply_y] && maply_x <= (int)ft_strlen(mlx->data->map2d[maply_y]))
		if (mlx->data->map2d[maply_y][maply_x] == '1')
			return (FALSE);
	return (TRUE);
}

int	check_direction(double angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI) //3&4 quadrant
			return (TRUE);
	}
	if (c == 'y')
	{
		if ((angle > 0 && angle > (M_PI / 2))
			&& (angle < (3 * M_PI) / 2)) //1&4quadrant
			return (TRUE);
	}
	return (FALSE);
}
