/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_any.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:52:29 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/08 14:21:00 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free_any(void **s)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	if (!s[0])
	{
		free(s);
		s = NULL;
		return ;
	}
	while (s[++i])
		free(s[i]);
	if (s)
	{
		free(s);
		s = NULL;
	}
}

// void	ft_free_any(void **s)
// {
// 	int	i;

// 	if (!s)
// 		return ;
// 	i = 0;
// 	while (s[i])
// 	{
// 		free(s[i]);
// 		s[i] = NULL;
// 		i++;
// 	}
// 	free(s);
// 	s = NULL;
// }
