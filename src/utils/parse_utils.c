/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:23:14 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/07 21:13:10 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	pr_str(t_file *f)
{
	t_file	*tpm;

	tpm = f;
	while (tpm)
	{
		ft_printf("tpm->s: %s\n", tpm->s);
		tpm = tpm->next;
	}
}

// void	print_data(t_data *data)
// {
// 	ft_printf("file:\n%s\n", data->file);
// 	pr_str(data->linked_file);
// 	ft_printf("map:\n");
// 	ft_putstr_double(data->map2d);
// }

// void	print_textures(t_data *data, int i)
// {
// 	ft_printf("\ni: %i\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n", i, data->north,
// 		data->south, data->west, data->east);
// 	ft_printf("F: %i,%i,%i\nC: %i,%i,%i\n\n", data->floor[0], data->floor[1],
// 		data->floor[2], data->ceiling[0], data->ceiling[1], data->ceiling[2]);
// }
