/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:20:43 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/01 17:53:17 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_file_list(t_file *file)
{
	t_file	*tmp;

	tmp = file;
	while (file)
	{
		file = file->next;
		free(tmp->s);
		free(tmp);
		tmp = file;
	}
}

void	free_textures(t_data *data)
{
	if (data->north)
		free(data->north);
	if (data->south)
		free(data->south);
	if (data->east)
		free(data->east);
	if (data->west)
		free(data->west);
}

void	*free_during_init(t_data *data)
{
	ft_printf("%sINIT_DATA FAIL%s\n", red, rst);
	ft_free(data->map2d);
	ft_free(data->square_map); //new add
	free_file_list(data->linked_file);
	free(data->file);
	free_textures(data);
	free(data);
	return (NULL);
}

void	free_mlx(t_mlx *game, int exit_code)
{
	// ft_printf("%sFREE_MLX%s\n" purple, reset);
	if (!game)
		exit(exit_code);
	if (game->mlx_p)
	{
		mlx_destroy_display(game->mlx_p);
		mlx_loop_end(game->mlx_p);
		free(game->mlx_p);
	}
	free(game);
	exit(exit_code);
}

void	ft_exit(t_mlx *mlx) //new add
{
	// temporary
	// mlx_destroy_image(mlx->mlx_p, mlx->img);
	mlx_destroy_window(mlx->mlx_p, mlx->win);
	free_file_list(mlx->file);
	free_textures(mlx->data);
	free_mlx(mlx, 0);
	// ft_putstr_fd("Game Closed\n", 1);
	exit(0);
}
