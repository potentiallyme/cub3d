/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:03:59 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/21 17:46:09 by yu-chen          ###   ########.fr       */
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

int	check_invalids(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S'
			|| map[i][j] == 'E' || map[i][j] == '1' || map[i][j] == '0'
			|| map[i][j] == ' ' || map[i][j] == '\n')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_file(t_data *data)
{
	int		i;
	t_file	*tmp;

	i = 0;
	i += check_textures(data, data->linked_file);
	tmp = data->linked_file;
	i += check_rgb(data, tmp, 'F');
	tmp = data->linked_file;
	i += check_rgb(data, tmp, 'C');
	i += check_invalids(data->map2d);
	i += check_map(make_square_map(data, 'G'));
	return (i);
}
