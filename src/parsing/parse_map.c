/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:14:00 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/11 17:29:33 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_invalid(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'D')
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

int	get_w(t_data *d)
{
	t_file *tmp;
	int line;

	tmp = return_map_start(d->linked_file);
	line = 0;
	while (tmp)
	{
		if (ft_strlen(tmp->s) > line)
			line = ft_strlen(tmp->s);
		tmp = tmp->next;
	}
	return (line);
}

int get_h(t_data *d)
{
	t_file *tmp;
	int line;

	tmp = return_map_start(d->linked_file);
	line = 0;
	while (tmp)
	{
		if (!ft_strchr(tmp->s, '1'))
			break ;
		line++;
		tmp = tmp->next;
	}
	return (line);
}

char	**make_square_map(t_data *m)
{
	int	i;
	int j;
	char **sq_map;

	i = -1;
	m->map_w = get_w(m);
	m->map_h = get_h(m);
	sq_map = my_malloc(&m->garbage, (m->map_h) + 1, sizeof * sq_map, DOUBLE);
	sq_map[m->map_h] = NULL;
	while (++i < m->map_h)
	{
		j = -1;
		sq_map[i] = malloc(sizeof * sq_map[i] * (m->map_w + 1));
		if (!sq_map[i])
			return (NULL);
		sq_map[i][m->map_w] = '\0';
		while (m->map2d[i][++j])
		{
			if (ft_isspace(m->map2d[i][j]))
				sq_map[i][j] = '1';
			else
				sq_map[i][j] = m->map2d[i][j];
		}
		while (j++ < m->map_w)
			sq_map[i][j] = '1';
	}
	return (sq_map);
}
