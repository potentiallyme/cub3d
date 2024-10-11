/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_garbo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:40:55 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/11 17:30:10 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*strdup_garbo(t_garbage **garbo, const char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = my_malloc(garbo, (ft_strlen(s) + 1), sizeof *str, SINGLE);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
