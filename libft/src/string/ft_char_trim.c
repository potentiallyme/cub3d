/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:50:18 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/25 19:02:38 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_char_trim(char *s, char trim)
{
	size_t	i;
	size_t	cst;
	size_t	cen;
	char	*ret;

	cst = 0;
	if (!s)
		return (NULL);
	while (s[cst] && s[cst] != trim)
		cst++;
	if (!s[cst])
		return (NULL);
	cst++;
	cen = ft_strlen(s);
	while (cen > cst && s[cen] != trim)
		cen--;
	if (cen == cst)
		return (NULL);
	ret = ft_calloc(sizeof(*s), (cen - cst + 1));
	i = 0;
	while (s[cst] && cst < cen)
		ret[i++] = s[cst++];
	ret[i] = '\0';
	return (ret);
}
