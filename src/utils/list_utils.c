/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:20:26 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/21 17:46:45 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	add_to_list(t_file **lst, t_file *new_node)
{
	t_file	*last;

	if (lst)
	{
		if (*lst)
		{
			last = *lst;
			while (last->next)
				last = last->next;
			new_node->next = NULL;
			last->next = new_node;
		}
		else
			*lst = new_node;
	}
}

int	is_texture_line(char *tmp, int *i)
{
	while (tmp[*i] == ' ' || tmp[*i] == '\t')
		(*i)++;
	if ((tmp[*i] == 'N' && tmp[*i + 1] == 'O' && tmp[*i + 2] == ' ')
		|| (tmp[*i] == 'S' && tmp[*i + 1] == 'O' && tmp[*i + 2] == ' ')
		|| (tmp[*i] == 'E' && tmp[*i + 1] == 'A' && tmp[*i + 2] == ' ')
		|| (tmp[*i] == 'W' && tmp[*i + 1] == 'E' && tmp[*i + 2] == ' '))
	{
		return (1);
	}
	return (0);
}

int	ft_strlen_tex(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	return (i);
}

void	check_and_add(t_data *data, t_file *new, char *tmp)
{
	t_file	*second;
	int		i;

	i = 0;
	second = NULL;
	if (is_texture_line(tmp, &i))
	{
		second = malloc(sizeof(t_file));
		if (!second)
			return ;
		second->s = NULL;
		second->next = NULL;
		new->s = ft_strndup(tmp + i, 2);
		second->s = ft_strndup(tmp + i + 3, ft_strlen_tex(tmp + i + 3));
		add_to_list(&data->linked_file, new);
		add_to_list(&data->linked_file, second);
	}
	else
	{
		new->s = ft_strdup(tmp);
		add_to_list(&data->linked_file, new);
	}
}

void	string_to_list(t_data *data)
{
	int		i;
	char	**tmp;
	t_file	*new;

	i = -1;
	if (!data->file)
		return ;
	tmp = ft_split(data->file, '\n');
	while (tmp[++i])
	{
		new = 0;
		new = malloc(sizeof(t_file));
		if (!new)
		{
			ft_free(tmp);
			return ;
		}
		new->s = NULL;
		new->next = NULL;
		check_and_add(data, new, tmp[i]);
	}
	new = 0;
	ft_free(tmp);
	free(data->file);
	data->file = 0;
}
