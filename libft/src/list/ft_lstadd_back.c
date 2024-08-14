/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:32:30 by nino              #+#    #+#             */
/*   Updated: 2024/07/23 23:56:07 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	new->interro = 0;
	if (lst)
	{
		if (*lst)
		{
			last = *lst;
			while (last->next)
				last = last->next;
			new->prev = last;
			new->next = NULL;
			last->next = new;
		}
		else
		{
			new->prev = NULL;
			*lst = new;
		}
	}
}
