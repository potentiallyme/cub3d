/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_double_garbo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:53:12 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/11 17:25:30 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	**strdup_double_garbo(t_garbage **garbo, char **s)
{
	int		i;
	char	**dup;

	i = 0;
	while (s[i])
		i++;
	dup = my_malloc(garbo, sizeof(char *), (i + 1), DOUBLE);
	if (!(dup))
		return (0);
	i = 0;
	while (s[i])
	{
		dup[i] = ft_strdup(s[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}
