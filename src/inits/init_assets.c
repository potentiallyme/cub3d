/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:55:12 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/17 20:56:59 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	mm_sec(t_mlx *game, t_data *data, int at, char *name)
{
	int	s;

	s = 20;
	data->asset[at] = mlx_xpm_file_to_image(data->mlx_p, name, &s, &s);
	if (!data->asset[at])
		data_error(game, data);
}
