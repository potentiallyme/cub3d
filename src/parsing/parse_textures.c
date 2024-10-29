/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:02:02 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/21 16:26:50 by yu-chen          ###   ########.fr       */
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

void	set_texture2(t_data *data)
{
	free(data->ply);
	data->ply = ft_strdup("./textures/gun_final.xpm");
	free(data->fire);
	data->fire = ft_strdup("./textures/gun_fire.xpm");
	if (!data->ply || !data->fire)
	{
		ft_printf("%sERROR\nPlayer .xpm wrong!%s\n", RED_PR, RST);
		return ;
	}
}

void	set_texture(t_data *data, t_file *file)
{
	if (!ft_strcmp(file->s, "NO") && file->next)
	{
		free(data->north);
		data->north = ft_strdup(file->next->s);
	}
	else if (!ft_strcmp(file->s, "SO") && file->next)
	{
		free(data->south);
		data->south = ft_strdup(file->next->s);
	}
	else if (!ft_strcmp(file->s, "EA") && file->next)
	{
		free(data->east);
		data->east = ft_strdup(file->next->s);
	}
	else if (!ft_strcmp(file->s, "WE") && file->next)
	{
		free(data->west);
		data->west = ft_strdup(file->next->s);
	}
	set_texture2(data);
}

int	recursive_check(t_data *data, t_file *file, char *s, int i)
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

int	check_textures(t_data *data, t_file *file)
{
	t_file	*tmp;
	int		i;

	tmp = file;
	i = recursive_check(data, tmp, "NO", 0);
	if (i != 4)
		return (0);
	return (1);
}
