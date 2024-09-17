/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:02:02 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/17 14:17:26 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*return_texture_paths(t_file *file, char *dir)
{
	t_file	*tmp;

	tmp = file;
	while (tmp)
	{
		if (!ft_strcmp(file->s, dir))
			return (file->next->s);
		tmp = tmp->next;
	}
	return (NULL);
}

void	set_texture(t_info *data, t_file *file)
{
	if (!ft_strcmp(file->s, "NO") && file->next)
		data->north = ft_strdup(file->next->s);
	else if (!ft_strcmp(file->s, "SO") && file->next)
		data->south = ft_strdup(file->next->s);
	else if (!ft_strcmp(file->s, "EA") && file->next)
		data->east = ft_strdup(file->next->s);
	else if (!ft_strcmp(file->s, "WE") && file->next)
		data->west = ft_strdup(file->next->s);
}

int	recursive_check(t_info *data, t_file *file, char *s, int i)
{
	t_file	*tmp;
	int		n;

	n = 0;
	tmp = file;
	while (tmp)
	{
		if (!ft_strcmp(tmp->s, s))
		{
			if (n == 0)
				set_texture(data, tmp);
			n++;
		}
		tmp = tmp->next;
	}
	if (i == 0)
		return (n + (recursive_check(data, file, "SO", 1)));
	else if (i == 1)
		return (n + (recursive_check(data, file, "WE", 2)));
	else if (i == 2)
		return (n + (recursive_check(data, file, "EA", 3)));
	return (n);
}

int	check_textures(t_info *data, t_file *file)
{
	t_file	*tmp;
	int		i;

	tmp = file;
	i = recursive_check(data, tmp, "NO", 0);
	if (i != 4)
		return (0);
	return (1);
}

int	check_texture_paths(t_info *data)
{
	int	len;

	len = ft_strlen(data->north);
	// ! CHECK STRUCTURES
	return (FAIL);
}
