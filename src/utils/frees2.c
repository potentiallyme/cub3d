/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:43:04 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/21 16:22:19 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_tex(t_tex *tex)
{
	if (tex->ply)
		free(tex->ply);
	if (tex->fire)
		free(tex->fire);
	if (tex->no)
		free(tex->no);
	if (tex->so)
		free(tex->so);
	if (tex->ea)
		free(tex->ea);
	if (tex->we)
		free(tex->we);
}

void	free_bonus(t_mlx *mlx)
{
	free(mlx->mm.nswe[0]);
	free(mlx->mm.nswe);
}

void	ft_exit(t_mlx *mlx, char *msg, int flag, int exit_code)
{
	ft_printf("%sERROR\n%s%s\n", RED, msg, RST);
	if (flag >= MLX)
		free_mlx(mlx);
	if (flag >= PARSER)
		free_data(&mlx->data);
	if (flag >= XPM)
		free_tex(&mlx->tex);
	if (flag >= TEX_PIX)
		ft_free_tab((void **)mlx->tex_pix);
	if (flag >= BNS && BONUS)
		free_bonus(mlx);
	exit(exit_code);
}

void	pre_exit(char *msg, int exit_code)
{
	ft_printf("%sERROR\n%s%s\n", RED, msg, RST);
	exit(exit_code);
}
