/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:52:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/14 16:46:13 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// ! STARTING PARSING HERE WILL MAKE OTHER FILES LATER

char	*return_gnl(int fd)
{
	int		i;
	char	*s;
	char	*t;

	i = 0;
	t = get_next_line(fd, 0);
	s = 0;
	while (t)
	{
		s = ft_strjoin(s, t, 0);
		free(t);
		t = get_next_line(fd, 0);
	}
	free(t);
	return (s);
}

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

void	string_to_list(t_info *data)
{
	int		i;
	char	**tmp;
	t_file	*new;

	i = 0;
	tmp = ft_split(data->file, ' ');
	while (tmp[i])
	{
		new = malloc(sizeof(t_file));
		new->s = ft_strdup(tmp[i]);
		add_to_list(&data->linked_file, new);
		i++;
	}
	ft_free(tmp);
}

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

int	recursive_check(t_file *file, char *s, int i)
{
	t_file	*tmp;
	int		n;

	n = 0;
	tmp = file;
	while (tmp)
	{
		if (!ft_strcmp(tmp->s, s))
			n++;
		tmp = tmp->next;
	}
	if (i == 0)
		return (n + (recursive_check(file, "SO", 1)));
	else if (i == 1)
		return (n + (recursive_check(file, "WE", 2)));
	else if (i == 2)
		return (n + (recursive_check(file, "EA", 3)));
	return (n);
}

int	check_textures(t_file *file)
{
	t_file	*tmp;

	tmp = file;
	if (recursive_check(tmp, "NO", 0) != 4)
		return (1);
}

int	check_file(t_info *data)
{
	int	i;

	i = check_textures(data->linked_file);
	i = check_rgb(data->linked_file);
	i = check_map(data->map);
}

void free_file_list(t_file *file)
{
	t_file *tmp;

	tmp = file;
	while (file)
	{
		file = file->next;
		free(tmp->s);
		free(tmp);
		tmp = file;
	}
}

void *free_during_init(t_info *data)
{
	ft_free(data->map);
	free_file_list(data->linked_file);
	free(data->file);
	free(data);
	return (NULL);
}

t_info	*init_data(char **av)
{
	t_info	*data;
	int		fd;
	char	c;

	fd = open(av[1], O_RDWR);
	data = malloc(sizeof(t_info));
	data->file = return_gnl(fd);
	string_to_list(data);
	data->map = 0; // ! MAKE MAP NEXT
	if (!check_file(data))
		return (free_during_init(data));
	data->north = return_texture_paths(data->linked_file, "NO");
	data->south = return_texture_paths(data->linked_file, "SO");
	data->west = return_texture_paths(data->linked_file, "WE");
	data->east = return_texture_paths(data->linked_file, "EA");
	data->floor = 0;
	data->ceiling = 0;
}

int	check_cub(char *s)
{
	int	len;

	len = ft_strlen(s);
	return (s[len] == 0 && s[len - 1] == 'b' && s[len - 2] == 'u'
			&& s[len - 3] == 'c' && s[len - 4] == '.');
}

void cub_three_d(char **av)
{
	t_info *data;
	
	data = init_data(av);
	if (!data)
		return ;
}

int	main(int ac, char **av)
{
	if ((ac != 2 || !check_cub(av[1])))
		return (0);
	cub_three_d(av);
	return (0);
}
