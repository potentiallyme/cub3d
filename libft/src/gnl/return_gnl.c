/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:56:08 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/11 17:14:23 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*return_gnl(int fd)
{
	char	*s;
	char	*t;

	t = get_next_line(fd, 0);
	s = 0;
	while (t)
	{
		if (!s)
			s = ft_strdup(t);
		else
			s = ft_strjoin(s, t, 1);
		free(t);
		t = get_next_line(fd, 0);
	}
	free(t);
	return (s);
}
