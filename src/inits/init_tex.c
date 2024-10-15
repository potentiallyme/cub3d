/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:53:03 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/15 13:42:42 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_tex(t_tex *tex)
{
	tex->ply = 0;
	tex->fire = 0;
	tex->no = 0;
	tex->so = 0;
	tex->ea = 0;
	tex->we = 0;
	tex->dir = 0;
	tex->pos = 0;
	tex->step = 0;
	tex->x = 0;
	tex->y = 0;
}

void	init_tex_pix(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->tex_pix)
		ft_free_tab((void **)mlx->tex_pix);
	mlx->tex_pix = cub_malloc(mlx, TEX_PIX, S_H + 1, sizeof * mlx->tex_pix);
	while (i < S_H)
	{
		mlx->tex_pix[i] = cub_malloc(mlx, TEX_PIX, (S_W + 1), sizeof * mlx->tex_pix[i]);
		i++;
	}
}