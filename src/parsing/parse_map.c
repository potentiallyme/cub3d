/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:14:00 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/15 14:05:46 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_around(char **map, int y, int x)
{
	if (y - 1 < 0 || x - 1 < 0)
		return (FAIL);
	if ((!map[y - 1][x - 1] || map[y - 1][x - 1] == 'E') || (!map[y - 1][x]
			|| map[y - 1][x] == 'E') || (!map[y - 1][x + 1] || map[y - 1][x
			+ 1] == 'E') || (!map[y][x - 1] || map[y][x - 1] == 'E')
		|| (!map[y][x + 1] || map[y][x + 1] == 'E') || (!map[y + 1][x - 1]
			|| map[y + 1][x - 1] == 'E') || (!map[y + 1][x] || map[y
			+ 1][x] == 'E') || (!map[y + 1][x + 1] || map[y + 1][x + 1] == 'E'))
		return (FAIL);
	return (SUCCESS);
}

int	check_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_invalid(map[y][x]) == TRUE)
				return (ft_free(map), FAIL);
			if (map[y][x] == '0' || is_player(map[y][x] == TRUE))
				if (check_around(map, y, x) == FAIL)
					return (ft_free(map), FAIL);
			x++;
		}
		y++;
	}
	ft_free(map);
	return (SUCCESS);
}

void	fill_square_map_line(char *sq_map_line, char *map_line, int width, char c)
{
	int	j;

	j = -1;
	while (map_line[++j])
	{
		if (ft_isspace(map_line[j]))
			sq_map_line[j] = c;
		else
			sq_map_line[j] = map_line[j];
	}
	while (j < width)
		sq_map_line[j++] = c;
	sq_map_line[width] = '\0';
}

char	**make_square_map(t_data *m, char c)
{
	int		i;
	char	**sq_map;

	m->map_w = get_w(m);
	m->map_h = get_h(m);
	sq_map = malloc(sizeof(char *) * (m->map_h + 1));
	if (!sq_map)
		return (NULL);
	sq_map[m->map_h] = NULL;
	i = -1;
	while (++i < m->map_h)
	{
		sq_map[i] = malloc(sizeof(char) * (m->map_w + 1));
		if (!sq_map[i])
			return (NULL);
		fill_square_map_line(sq_map[i], m->map2d[i], m->map_w, c);
	}
	return (sq_map);
}
