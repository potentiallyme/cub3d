/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:14:00 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/07 21:30:22 by lmoran           ###   ########.fr       */
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
	int w;
	int h;
	char **tmp;
	char **sq_map;

	i = 0;
	w = get_w(m);
	h = get_h(m);
	sq_map = malloc(sizeof(char *) * h);
	tmp = m->map2d;
	sq_map[h] = NULL;
	while (i < h)
	{
		j = 0;
		sq_map[i] = malloc(sizeof(char) * w + 1);
		sq_map[i][w] = '\0';
		while (tmp[i][j])
		{
			if (tmp[i][j] == ' ')
				sq_map[i][j] = '1';
			else
				sq_map[i][j] = tmp[i][j];
			j++;
		}
		while (j < w)
		{
			sq_map[i][j] = '1';
			j++;
		}
		i++;
	}
	ft_putstr_double(sq_map);
	return (sq_map);
}
