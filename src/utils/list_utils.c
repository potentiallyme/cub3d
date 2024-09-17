/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:20:26 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/17 14:20:29 by lmoran           ###   ########.fr       */
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

void	check_and_add(t_info *data, t_file *new, char *tmp)
{
	t_file *second;
	int i;

 	while (tmp[i] == ' ')
		i++;
	if ((tmp[i] == 'N' && tmp[i + 1] == 'O' && tmp[i + 2] == ' ') ||
		(tmp[i] == 'S' && tmp[i + 1] == 'O' && tmp[i + 2] == ' ') ||
		(tmp[i] == 'E' && tmp[i + 1] == 'A' && tmp[i + 2] == ' ') ||
		(tmp[i] == 'W' && tmp[i + 1] == 'E' && tmp[i + 2] == ' '))
	{
		second = malloc(sizeof(t_file));
		new->s = ft_strndup(tmp + i, 2);
		second->s = ft_strdup(tmp + i + 3);
		add_to_list(&data->linked_file, new);
		add_to_list(&data->linked_file, second);
	}
	else
	{
		new->s = ft_strdup(tmp);
		add_to_list(&data->linked_file, new);
	}
}

void	string_to_list(t_info *data)
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
		new = malloc(sizeof(t_file));
		check_and_add(data, new, tmp[i]);
		i++;
	}
	ft_free(tmp);
}
