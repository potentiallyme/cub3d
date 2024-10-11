/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_garbo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:13:18 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/11 17:28:25 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*strjoin_garbo(t_garbage **garbo, char *s1, char *s2, int f)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1)
		return (strdup_garbo(garbo, s2));
	s3 = my_malloc(garbo, sizeof *s3, (ft_strlen(s1) + ft_strlen(s2) + 1), SINGLE);
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i++] = s2[j++];
	}
	s3[i] = '\0';
	if (f)
		free(s1);
	return (s3);
}
