/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:10:52 by nclassea          #+#    #+#             */
/*   Updated: 2023/11/16 11:44:29 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	out;

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
