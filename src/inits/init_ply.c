/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:55:12 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/09 14:18:36 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_player(t_data *data, char c)
{
	if (c == 'N')
		data->player_dir = NO;
	else if (c == 'S')
		data->player_dir = SO;
	else if (c == 'W')
		data->player_dir = WE;
	else if (c == 'E')
		data->player_dir = EA;
}

int	get_player_pos(t_data *data)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	n = 0;
	while (data->square_map[++i])
	{
		j = -1;
		while (data->square_map[i][++j])
		{
			if (is_player(data->square_map[i][j]))
			{
				data->p_x = j;
				data->p_y = i;
				set_player(data, data->square_map[i][j]);
				data->square_map[i][j] = '0';
				n++;
			}
		}
	}
	return (n);
}

void	set_player_cam(t_player **ply)
{
	if ((*ply)->nswe == SO)
	{
		(*ply)->dir_x = 0;
		(*ply)->dir_y = 1;
		(*ply)->plane_x = -0.66;
		(*ply)->plane_y = 0;
	}
	else if ((*ply)->nswe == EA)
	{
		(*ply)->dir_x = 1;
		(*ply)->dir_y = 0;
		(*ply)->plane_x = 0;
		(*ply)->plane_y = 0.66;
	}
	else if ((*ply)->nswe == WE)
	{
		(*ply)->dir_x = -1;
		(*ply)->dir_y = 0;
		(*ply)->plane_x = 0;
		(*ply)->plane_y = -0.66;
	}
}

void	init_player(t_mlx *mlx, t_player *ply)
{
	if (get_player_pos(&mlx->data) != 1)
		ft_exit(mlx, "Only one player is accepted", PARSER, 1);
	ply->ply_x = mlx->data.p_x + 0.5;
	ply->ply_y = mlx->data.p_y + 0.5;
	ply->nswe = mlx->data.player_dir;
	ply->dir_x = 0;
	ply->dir_y = -1;
	ply->plane_x = 0.66;
	ply->plane_y = 0;
	set_player_cam(&ply);
	ply->has_moved = 0;
	ply->move_x = 0;
	ply->move_y = 0;
	ply->rot_r = 0;
	ply->rot_l = 0;
	ply->sprint = 0;
	ply->gauge = 100;
	ply->fire = 0;
}
