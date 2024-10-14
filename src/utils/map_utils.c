/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:15:52 by yu-chen           #+#    #+#             */
/*   Updated: 2024/10/14 14:11:02 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_h_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	*fill_map(char *map_line, int maxlen)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(sizeof(char), maxlen + 1);
	if (!new)
		return (NULL);
	while (map_line[i])
	{
		new[i] = map_line[i];
		i++;
	}
	while (i < maxlen)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	check_w_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (i > 0 && (map[i][j - 1] == ' ' || map[i][j + 1] == ' '))
				{
					ft_printf("ERROR\nINVALID MAP!\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_h_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (i > 0 && (map[i - 1][j] == ' ' || map[i + 1][j] == ' '))
				{
					ft_printf("ERROR\nINVALID MAP!\n\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

long	get_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b << 0);
}
