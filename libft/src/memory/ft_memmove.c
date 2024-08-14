/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:54:21 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/18 16:19:22 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*source;
	char	*destination;

	i = -1;
	source = (char *)src;
	destination = (char *)dest;
	if (!destination && !source)
		return (NULL);
	if (destination > source)
	{
		while (n-- > 0)
			destination[n] = source[n];
	}
	else
	{
		while (++i < n)
			destination[i] = source[i];
	}
	return (destination);
}
