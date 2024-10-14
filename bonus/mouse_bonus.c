/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:26:07 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/14 15:34:07 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	mouse_move(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(mlx->mlx_p, mlx->win, &x, &y);
	if (x > S_W / 2 + 1)
		rotate_view(mlx, 0.07);
	if (x < S_W / 2 - 1)
		rotate_view(mlx, -0.07);
	if (x < 0 || x > S_W)
	mlx_mouse_move(mlx->mlx_p, mlx->win, S_W / 2, S_H / 2);
	return (1);
}
//!chatgpt
// int mouse_move(t_mlx *game, int x)
// {
//     static int prev_x = S_W / 2;

//     if (x > prev_x) // 滑鼠向右移動
//         rotate_view(game, 0.05);  // 根據需要調整旋轉的角度值
//     else if (x < prev_x) // 滑鼠向左移動
//         rotate_view(game, -0.05);

//     prev_x = x;
//     mlx_mouse_move(game->mlx_p, game->win, S_W / 2, S_H / 2);  // 將滑鼠位置重置到螢幕中央
//     return (0);
// }

//! mcom way
// static void	wrap_mouse_position(t_mlx *mlx, int x, int y)
// {
// 	if (x > S_W - 20)
// 	{
// 		x = 20;
// 		mlx_mouse_move(mlx->mlx_p, mlx->win, x, y);
// 	}
// 	if (x < 20)
// 	{
// 		x = S_W - 20;
// 		mlx_mouse_move(mlx->mlx_p, mlx->win, x, y);
// 	}
// }

// int	mouse_move(t_mlx *mlx, int x, int y)
// {
// 	static int	old_x = S_W / 2;

// 	wrap_mouse_position(mlx, x, y);
// 	if (x == old_x)
// 		return (0);
// 	else if (x < old_x)
// 		mlx->ply.has_moved += rotate_view(mlx, -1);
// 	else if (x > old_x)
// 		mlx->ply.has_moved += rotate_view(mlx, 1);
// 	old_x = x;
// 	return (0);
// }
