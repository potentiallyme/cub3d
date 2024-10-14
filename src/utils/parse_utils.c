/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:23:14 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/14 19:12:00 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	pr_str(t_file *f)
{
	t_file	*tpm;

	tpm = f;
	while (tpm)
	{
		// ft_printf("tpm->s: %s\n", tpm->s);
		tpm = tpm->next;
	}
}

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
		if (!ft_strchr(tmp->s, '1'))
			break ;
		line++;
		tmp = tmp->next;
	}
	return (line);
}

int	is_invalid(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == 'D')
		return (FALSE);
	return (TRUE);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}
