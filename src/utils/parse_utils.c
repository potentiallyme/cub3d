/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:23:14 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/21 16:18:33 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_w(t_data *d)
{
	t_file	*tmp;
	int		line;

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

int	get_h(t_data *d)
{
	t_file	*tmp;
	int		line;

	tmp = return_map_start(d->linked_file);
	line = 0;
	while (tmp)
	{
		if (!tmp->s)
			break ;
		line++;
		tmp = tmp->next;
	}
	return (line);
}

int	is_invalid(char c)
{
	if (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == 'G')
		return (FALSE);
	return (TRUE);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}
