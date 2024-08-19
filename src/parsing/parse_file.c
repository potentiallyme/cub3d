/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:03:59 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/19 16:36:37 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_file(t_info *data)
{
	int	i;

	i = check_textures(data, data->linked_file);
	ft_printf("i: %i\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n", i, data->north, data->south, data->west, data->east);
	// i = check_texture_paths(data);
	// i = check_rgb(data->linked_file);
	// i = check_map(data->map2d);
	return (i);
}
