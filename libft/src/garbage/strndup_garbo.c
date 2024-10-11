/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup_garbo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:06:19 by nino              #+#    #+#             */
/*   Updated: 2024/10/11 17:24:08 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*strndup_garbo(t_garbage **garbo, const char *s, int n)
{
	char	*dup;
	int i;
	int	len;

	if (!s)
		return (NULL);
	len = 0;
	i = 0;
	if (len < n)
		len = n;
	dup = my_malloc(garbo, sizeof * dup, (len + 1), SINGLE);
	while (n && s[i])
	{
		dup[i] = s[i];
		i++;
		n--;
	}
	dup[i] = 0;
	return (dup);
}
