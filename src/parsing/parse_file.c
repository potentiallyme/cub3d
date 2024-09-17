/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:03:59 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/17 14:24:02 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_format(char **s)
{
	int	n;
	int	i;

	if (!s || !s[2])
		return (FAIL);
	i = 0;
	while (s[i])
	{
		n = ft_atoi(s[i]);
		if (n < 0 || n > 255 || i > 2)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	recheck_format(int *i)
{
	int	j;

	j = 0;
	while (i[j])
	{
		ft_printf("i[%i] = %i\n", j, i[j]);
		if (i[j] < 0 || i[j] > 255)
			return (0);
		j++;
	}
	return (1);
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

int rgb_error(t_info *data, char c)
{
	if (c == 'F')
		data->floor[0] = -1;
	else if (c == 'C')	
		data->ceiling[0] = -1;
	return (0);
}

int	check_rgb(t_info *data, t_file *tmp, char c)
{
	char	**split;
	int		n;
	int 	i;

	n = 0;
	i = 0;
	while (tmp)
	{
		while (tmp->s[i] == ' ')
			i++;
		if (tmp->s[i] == c && tmp->s[i + 1] == ' ')
		{
			split = ft_split(tmp->s + i + 2, ',');
			if (n == 0 && check_format(split))
				set_rgb(data, split, c);
			else
				return (rgb_error(data, c));
			n++;
		}
		tmp = tmp->next;
		i = 0;
	}
	if (c == 'F')
		return (n + recheck_format(data->floor));
	return (n + recheck_format(data->ceiling));
}

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

int	check_file(t_info *data)
{
	int	i;
	t_file	*tmp;

	i = 0;
	i += check_textures(data, data->linked_file);
	tmp = data->linked_file;
	i += check_rgb(data, tmp, 'F');
	tmp = data->linked_file;
	i += check_rgb(data, tmp, 'C');
	// i = check_map(data->map2d);
	// i = check_texture_paths(data); // ? IMG TO FILE part
	print_textures(data, i);
	return (i);
}
