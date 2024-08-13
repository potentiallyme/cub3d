/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:22:15 by lmoran            #+#    #+#             */
/*   Updated: 2024/07/04 16:51:54 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_count_chars(char *s, char *chars)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	j = -1;
	ret = 0;
	while (s[++i])
	{
		while (chars[++j])
		{
			if (s[i] == chars[j])
				ret++;
		}
		j = 0;
	}
	return (ret);
}
