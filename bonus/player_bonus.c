/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:31:42 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/14 12:53:46 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	render_player(t_mlx *mlx, t_image *img)
{
	int	y;
	int	x;
	int	hx;
	int	hy;

	y = 280;
	hy = 0;
	if (mlx->ply.fire == 0 || mlx->gun == mlx->tex.fire)
		mlx->gun = mlx->tex.ply;
	else
		mlx->gun = mlx->tex.fire;
	while (y < S_H)
	{	
		x = 280;
		hx = 0;
		while (x < 520)
		{
			if (mlx->gun[hy * 240 + hx] > 0)
				draw_pix(img, x, y, mlx->gun[hy * 240 + hx]);
			x++;
			hx++;
		}
		hy++;
		y++;
	}
}
