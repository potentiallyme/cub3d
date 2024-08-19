/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:54:42 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/14 18:09:32 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int is_png(char *s)
{
	int	len;

	len = ft_strlen(s);
	return (s[len] == 0 && s[len - 1] == 'g' && s[len - 2] == 'n' && s[len
		- 3] == 'p' && s[len - 4] == '.');
}

int	is_xpm(char *s)
{
	int	len;

	len = ft_strlen(s);
	return (s[len] == 0 && s[len - 1] == 'm' && s[len - 2] == 'p' && s[len
		- 3] == 'x' && s[len - 4] == '.');
}

int	is_cub(char *s)
{
	int	len;

	len = ft_strlen(s);
	return (s[len] == 0 && s[len - 1] == 'b' && s[len - 2] == 'u' && s[len
		- 3] == 'c' && s[len - 4] == '.');
}
