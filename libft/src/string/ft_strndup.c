/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:06:19 by nino              #+#    #+#             */
/*   Updated: 2024/08/19 18:02:21 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strndup(const char *s, int n)
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
	dup = (char *)malloc(sizeof(char) * (len + 1));
	while (n && s[i])
	{
		dup[i] = s[i];
		i++;
		n--;
	}
	dup[i] = 0;
	return (dup);
}
