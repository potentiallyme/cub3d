/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:56:28 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/11 16:38:05 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	free_garbage(t_garbage **garbage, char *msg)
{
	t_garbage	*temp;

	*(*garbage)->garbage_freed = 1;
	printf("Garbage Free: %s%s%s\n", red, msg, rst);
	while (*garbage != NULL)
	{
		temp = *garbage;
		*garbage = (*garbage)->next;
		if (temp->ptr && temp->dbl)
			ft_free(temp->ptr);
		if (temp->ptr)
			free(temp->ptr);
		temp->ptr = NULL;
		free(temp);
	}
	*garbage = NULL;
}

void	ft_lstadd_garbo(t_garbage **lst, void *new, int dbl)
{
	t_garbage	*new_g;
	t_garbage	*last;

	new_g = malloc(1 * sizeof * new_g);
	if (!new_g)
	{
		free_garbage(lst, "Lstadd malloc error");
		return ;
	}
	new_g->ptr = new;
	new_g->next = NULL;
	new_g->dbl = dbl;
	if (lst && *lst)
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new_g;
	}
	else
		*lst = new_g;
}

void	*my_malloc(t_garbage **garbage, size_t nmemb, size_t size, int dbl)
{
	char	*ptr;

	if (size == 0)
		return (malloc(0));
	if (nmemb <= 0 && size <= 0)
		return (NULL);
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
	{
		free_garbage(garbage, "My_malloc error");
		return (NULL);
	}
	ft_bzero(ptr, nmemb * size);
	ft_lstadd_garbo(garbage, ptr, dbl);
	return ((void *)ptr);
}
