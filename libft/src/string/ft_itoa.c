/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:05:59 by nclassea          #+#    #+#             */
/*   Updated: 2024/07/04 16:52:14 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static unsigned long	ft_nb_size(long nb)
{
	unsigned long	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len += 1;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long n)
{
	char	*str;
	long	size;
	long	nb;

	nb = n;
	size = ft_nb_size(nb);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[size] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	size--;
	while (nb)
	{
		str[size] = ((nb % 10) + '0');
		size--;
		nb /= 10;
	}
	return (str);
}

// long	main(void)
// {
// 	__builtin_prlongf("%s", ft_itoa(18437));
// }
