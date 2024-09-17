/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:14:00 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/17 14:27:15 by lmoran           ###   ########.fr       */
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
