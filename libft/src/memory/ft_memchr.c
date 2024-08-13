/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:36:21 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:46:46 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	unsigned const char	*str;

	str = (unsigned const char *)s;
	while (size--)
	{
		if (*str == (unsigned const char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
