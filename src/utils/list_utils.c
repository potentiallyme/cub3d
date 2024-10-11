/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:20:26 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/11 17:26:34 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	add_to_list(t_file **lst, t_file *new)
{
	t_file	*last;

	if (lst)
	{
		if (*lst)
		{
			last = *lst;
			while (last->next)
				last = last->next;
			new->next = NULL;
			last->next = new;
		}
		else
			*lst = new;
	}
}

void	check_and_add(t_data *data, t_file *new, char *tmp)
{
	t_file *second;
	int i;

	i = 0;
	second = 0;
 	while (tmp[i] == ' ')
		i++;
	if ((tmp[i] == 'N' && tmp[i + 1] == 'O' && tmp[i + 2] == ' ') ||
		(tmp[i] == 'S' && tmp[i + 1] == 'O' && tmp[i + 2] == ' ') ||
		(tmp[i] == 'E' && tmp[i + 1] == 'A' && tmp[i + 2] == ' ') ||
		(tmp[i] == 'W' && tmp[i + 1] == 'E' && tmp[i + 2] == ' '))
	{
		second = 0;
		second = my_malloc(&data->garbage, sizeof * second, 1, SINGLE);
		new->s = strndup_garbo(&data->garbage, tmp + i, 2);
		second->s = strdup_garbo(&data->garbage, tmp + i + 3);
		add_to_list(&data->linked_file, new);
		add_to_list(&data->linked_file, second);
	}
	else
	{
		new->s = strdup_garbo(&data->garbage, tmp);
		add_to_list(&data->linked_file, new);
	}
}

void	string_to_list(t_data *data)
{
	int		i;
	char	**tmp;
	t_file	*new;

	i = 0;
	if (!data->file)
		return ;
	tmp = ft_split(data->file, '\n');
	while (tmp[i])
	{
		new = 0;
		new = my_malloc(&data->garbage, sizeof * new, 1, SINGLE);
		check_and_add(data, new, tmp[i]);
		i++;
	}
	new = 0;
	ft_free(tmp);
	free(data->file);
	data->file = 0;
}
