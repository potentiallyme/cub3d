/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:46:33 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/19 16:31:56 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int check_if_map(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '1')
		i++;
	if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '1')
		return (1);
	return (0);
}

t_file *return_map_start(t_file *file)
{
	t_file *tmp;

	tmp = file;
	while (tmp)
	{
		if (ft_strchr(tmp->s, '1') && ft_strrchr(tmp->s, '1'))
		{
			if (check_if_map(tmp->s))
				return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int count_lines(t_file *file)
{
	t_file *tmp;
	int c;

	tmp = file;
	c = 0;
	while (tmp)
	{
		c++;
		tmp = tmp->next;	
	}
	return (c);
}

char **return_map(t_info *data)
{
	t_file *tmp;
	char **map;
	int i;
	
	tmp = return_map_start(data->linked_file);
	if (!tmp)
		return (NULL);
	map = (char **)malloc((count_lines(tmp) + 1) * sizeof(char *));
	i = 0;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->s);
		tmp = tmp->next;
		i++;
	}
	map[i] = 0;
	return (map);
}
