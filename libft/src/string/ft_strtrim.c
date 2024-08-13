/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:04:19 by lmoran            #+#    #+#             */
/*   Updated: 2024/07/24 11:30:16 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	cst;
	size_t	cen;
	char	*ret;

	cst = 0;
	if (!s)
		return (NULL);
	while (s[cst] && ft_strchr(set, s[cst]))
		cst++;
	cen = ft_strlen(s);
	while (cen > cst && ft_strchr(set, s[cen - 1]))
		cen--;
	ret = ft_calloc(cen - cst + 1, sizeof(*s));
	if (!ret)
		return (NULL);
	i = 0;
	while (cst < cen)
		ret[i++] = s[cst++];
	ret[i] = '\0';
	return (ret);
}
