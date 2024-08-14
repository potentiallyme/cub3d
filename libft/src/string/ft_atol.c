/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:28:27 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/30 17:27:38 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

long	ft_atol(char *nptr)
{
	long	sign;
	long	out;

	out = 0;
	sign = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '-')
	{
		sign++;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= 48 && *nptr <= 57)
	{
		out *= 10;
		out += *nptr - 48;
		nptr++;
	}
	if (sign == 1)
		out *= -1;
	return (out);
}
