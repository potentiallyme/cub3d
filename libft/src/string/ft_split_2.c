/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:16:49 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/19 14:37:30 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	ft_countword(char const *s, char c1, char c2)
{
	size_t	count;
	int i;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c1 || s[i] == c2)
			i++;
		if (s[i])
			count++;
		while ((s[i] != c1 || s[i] != c2) && s[i])
			i++;
	}
	return (count);
}

char	**ft_split_2(char const *s, char c1, char c2)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c1, c2) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while ((*s == c1 || *s == c2) && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c1) && !ft_strchr(s, c2))
				word_len = ft_strlen(s);
			else if (ft_strchr(s, c1))
				word_len = ft_strchr(s, c1) - s;
			else if (ft_strchr(s, c2))
				word_len = ft_strchr(s, c2) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
