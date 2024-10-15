/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:17 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/15 13:14:42 by yu-chen          ###   ########.fr       */
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
		{
			ft_printf("%sERROR\nRGB WRONG!%s\n", RED_PR, RST);
			return (FAIL);
		}
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
		if (i[j] < 0 || i[j] > 255)
			return (0);
		j++;
	}
	return (1);
}

void	set_rgb(t_data *data, char **split, char c)
{
	if (c == 'F')
	{
		data->c_floor = ft_strdup_double(split);
		data->floor = get_color(ft_atoi(split[0]), ft_atoi(split[1]),
				ft_atoi(split[2]));
	}
	else if (c == 'C')
	{
		data->c_ceiling = ft_strdup_double(split);
		data->ceiling = get_color(ft_atoi(split[0]), ft_atoi(split[1]),
				ft_atoi(split[2]));
	}
	ft_free(split);
}

int	rgb_error(t_data *data, char c)
{
	if (c == 'F')
		data->floor = -1;
	else if (c == 'C')
		data->ceiling = -1;
	return (0);
}

int	check_rgb(t_data *data, t_file *tmp, char c)
{
	char	**split;
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (tmp)
	{
		while (tmp->s[i] == ' ')
			i++;
		if (tmp->s[i] == c && tmp->s[i + 1] == ' ')
		{
			split = ft_split(tmp->s + i + 2, ',');
			// if (!split)
			// 	return (rgb_error(data,c)); 
			if (n == 0 && check_format(split))
				set_rgb(data, split, c);
			else
				return (rgb_error(data, c));
			n++;
		}
		tmp = tmp->next;
		i = 0;
	}
	return (n);
}
