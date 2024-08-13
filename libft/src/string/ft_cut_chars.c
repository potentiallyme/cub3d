/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:19 by lmoran            #+#    #+#             */
/*   Updated: 2024/07/18 16:23:15 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_cut_chars(char *s, char *cut)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*tmp;

	len = ft_strlen(s) - ft_count_chars(s, cut) + 1;
	tmp = (char *)malloc(len * sizeof(char));
	i = -1;
	k = 0;
	while (tmp[++i])
	{
		j = -1;
		while (cut[++j])
		{
			if (s[k] == cut[j])
				k++;
		}
		tmp[i] = s[k];
		k++;
	}
	tmp[i] = 0;
	return (tmp);
}
