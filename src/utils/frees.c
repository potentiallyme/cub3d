/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:20:43 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/11 15:27:27 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_mlx(t_mlx *game, int exit_code)
{
	if (game->mlx_p)
	{
		mlx_destroy_display(game->mlx_p);
		mlx_loop_end(game->mlx_p);
		free(game->mlx_p);
	}
	exit(exit_code);
}

void free_tex(t_tex *tex)
{
	if (tex->no)
		free(tex->no);
	if (tex->so)
		free(tex->so);
	if (tex->ea)
		free(tex->ea);
	if (tex->we)
		free(tex->we);
}

void	ft_exit(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx_p, mlx->win);
	if (mlx->mlx_p)
	{
		mlx_destroy_display(mlx->mlx_p);
		mlx_loop_end(mlx->mlx_p);
		free(mlx->mlx_p);
	}
	ft_printf("%sFT_EXIT%s\n", red, rst);
	exit(0);
}

void full_exit(t_mlx *mlx, char *msg)
{
	free_garbage(&mlx->garbage, msg);
	ft_exit(mlx);
}
