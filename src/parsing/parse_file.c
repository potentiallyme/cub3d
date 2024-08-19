/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:03:59 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/19 18:30:36 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_format(char **s)
{
	int	n;
	int	i;

	if (!s || !s[2])
		return (0);
	i = 0;
	while (s[i])
	{
		n = ft_atoi(s[i]);
		if (n < 0 || n > 255 || i > 2)
			return (0);
		i++;
	}
	return (1);
}

int recheck_format(int *i)
{
	int j;

	j = 0;
	while (i[j])
	{
		if (i[j] < 0 || i[j] > 255)
			return (1);
		j++;
	}
	return (0);
}

void	set_rgb(t_info *data, char **split, char c)
{
	if (c == 'F')
	{
		data->floor[0] = ft_atoi(split[0]);
		data->floor[1] = ft_atoi(split[1]);
		data->floor[2] = ft_atoi(split[2]);
	}
	else if (c == 'C')
	{
		data->ceiling[0] = ft_atoi(split[0]);
		data->ceiling[1] = ft_atoi(split[1]);
		data->ceiling[2] = ft_atoi(split[2]);
	}
	ft_free(split);
}

int	check_rgb(t_info *data, char c)
{
	t_file	*tmp;
	char	**split;
	int		n;

	tmp = data->linked_file;
	n = 0;
	while (tmp)
	{
		if (tmp->s[0] == c && tmp->s[1] == ' ')
		{
			split = ft_split(tmp->s + 2, ',');
			if (n == 0 && check_format(split))
				set_rgb(data, split, c);
			n++;
		}
		tmp = tmp->next;
	}
	if (c == 'F')
		return (n + recheck_format(data->floor));
	return (n + recheck_format(data->ceiling));
}

void	print_textures(t_info *data, int i)
{
	ft_printf("i: %i\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n", i, data->north,
		data->south, data->west, data->east);
	ft_printf("F: %i,%i,%i\nC: %i,%i,%i\n", data->floor[0], data->floor[1],
		data->floor[2], data->ceiling[0], data->ceiling[1], data->ceiling[2]);
}

int	check_file(t_info *data)
{
	int	i;

	i = 0;
	i += check_textures(data, data->linked_file);
	i += check_rgb(data, 'F');
	i += check_rgb(data, 'C');
	print_textures(data, i);
	// i = check_map(data->map2d);
	// i = check_texture_paths(data); // ? IMG TO FILE part
	return (i);
}
