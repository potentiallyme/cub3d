/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:26:07 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/15 14:56:08 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	mouse_move(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(mlx->mlx_p, mlx->win, &x, &y);
	if (x > S_W / 2 + 100)
		rotate_view(mlx, 0.75);
	if (x < S_W / 2 - 100)
		rotate_view(mlx, -0.75);
	if (x < 0 || x > S_W)
		mlx_mouse_move(mlx->mlx_p, mlx->win, S_W / 2, S_H / 2);
	return (1);
}
