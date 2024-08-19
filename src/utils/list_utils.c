/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:57:27 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/19 16:26:03 by lmoran           ###   ########.fr       */
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
	int	i;
	t_file *second;

	i = 0;
	second = 0;
	if ((tmp[0] == 'N' && tmp[1] == 'O' && tmp[2] == ' ') ||
		(tmp[0] == 'S' && tmp[1] == 'O' && tmp[2] == ' ') ||
		(tmp[0] == 'E' && tmp[1] == 'A' && tmp[2] == ' ') ||
		(tmp[0] == 'W' && tmp[1] == 'E' && tmp[2] == ' '))
	{
		second = malloc(sizeof(t_file));
		new->s = ft_strndup(tmp, 2);
		second->s = ft_strdup(tmp + 3);
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
