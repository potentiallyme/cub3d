/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:06:19 by nino              #+#    #+#             */
/*   Updated: 2024/07/04 16:56:27 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	len;

	len = strlen(s);
	if (n < len)
		len = n;
	dup = malloc(len + 1);
	if (dup)
	{
		ft_memcpy(dup, s, len);
		dup[len] = '\0';
	}
	return (dup);
}
