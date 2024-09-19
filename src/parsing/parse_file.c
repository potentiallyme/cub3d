/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:03:59 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/19 17:55:26 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	**fill_spaces(char **map)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = ft_strdup_double(map);
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == ' ')
				s[i][j] = 'E';
			j++;
		}
		i++;
	}
	return (s);
}

int	check_file(t_data *data)
{
	int	i;
	t_file	*tmp;

	i = 0;
	i += check_textures(data, data->linked_file);
	tmp = data->linked_file;
	i += check_rgb(data, tmp, 'F');
	tmp = data->linked_file;
	i += check_rgb(data, tmp, 'C');
	i += check_map(fill_spaces(data->map2d));
	// i = check_texture_paths(data); // ?  TO FILE part
	print_textures(data, i);
	return (i);
}
