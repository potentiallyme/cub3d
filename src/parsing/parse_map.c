/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:14:00 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/03 15:56:04 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_invalid(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (FALSE);
	return (TRUE);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}
int	check_around(char **map, int y, int x)
{
	if (y - 1 < 0 || x - 1 < 0)
		return (FAIL);
	// if ((y + 1) > ft_strlen(map[y]) || (x + 1) > ft_linelen(map))
	// 	return (FAIL);
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

char	**make_square_map(t_data *m) //new add
{
	int	i;
	int maxlen;

	maxlen = get_maxlen(m->map2d);
	i = 0;
	m->square_map = ft_calloc(sizeof(char *), get_h_map(m->map2d + 1));
	if (!m->square_map)
		return (NULL);
	while (m->map2d[i])
	{
		if (ft_strlen(m->map2d[i]) == maxlen)
			m->square_map[i] = ft_strdup(m->map2d[i]);
		else
			m->square_map[i] = fill_map(m->map2d[i], maxlen);
		if (!m->square_map[i])
		{
			free_during_init(m);
			return (NULL);
		}
		i++;
	}
	m->square_map[i] = NULL;
	m->map_h = get_h_map(m->square_map);
	m->map_w = maxlen;
	if (!check_w_map(m->square_map) || !check_h_map(m->square_map)) //or just check_map? or check_around?
		return (free_during_init(m), NULL);
	return (m->square_map);
}
