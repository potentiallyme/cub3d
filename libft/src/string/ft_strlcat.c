/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:44:34 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:45:38 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dest_len;
	size_t		total_len;
	const char	*s;

	if ((!dst || !src) && !size)
		return (0);
	s = src;
	dest_len = 0;
	while (*(dst + dest_len) && dest_len < size)
		dest_len++;
	if (dest_len < size)
		total_len = dest_len + ft_strlen(s);
	else
		return (size + ft_strlen(s));
	while (*s && (dest_len + 1) < size)
	{
		*(dst + dest_len) = *s++;
		dest_len++;
	}
	*(dst + dest_len) = '\0';
	return (total_len);
}
