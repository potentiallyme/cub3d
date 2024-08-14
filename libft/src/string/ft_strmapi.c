/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:52:05 by lmoran            #+#    #+#             */
/*   Updated: 2023/12/16 05:45:49 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*ret;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ret = malloc(sizeof(*s) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = 0;
	while (i < len)
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	return (ret);
}
