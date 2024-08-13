/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:51 by nclassea          #+#    #+#             */
/*   Updated: 2024/07/09 15:00:38 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *) big);
	else if (len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && big [i + j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return ((char *) big + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
