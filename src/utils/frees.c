/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:02:57 by lmoran            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/12 13:46:52 by lmoran           ###   ########.fr       */
=======
/*   Updated: 2024/09/16 19:01:00 by lmoran           ###   ########.fr       */
>>>>>>> refs/remotes/origin/lmoran
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

void	free_textures(t_info *data)
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

void	*free_during_init(t_info *data)
{
	ft_free(data->map2d);
	free_file_list(data->linked_file);
	free(data->file);
	free_textures(data);
	free(data);
	ft_printf("EXITING\n");
	return (NULL);
}

void	free_mlx(t_data *game, int exit_code)
{
	ft_printf("FREE_MLX\n");
	if (!game)
		exit(exit_code);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(exit_code);
}
