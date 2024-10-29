/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:13:53 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/15 14:13:54 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
