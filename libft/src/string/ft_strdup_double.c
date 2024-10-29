/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:53:12 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/15 13:15:44 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	**ft_strdup_double(char **s)
{
	int		i;
	char	**dup;

	i = 0;
	while (s[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
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
