/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:13:19 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/18 16:19:22 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static unsigned int	ft_nb_size(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		size;
	long	nb;

	nb = n;
	size = ft_nb_size(nb);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[size] = '\0';
	size--;
	while (nb)
	{
		str[size] = ((nb % 10) + '0');
		size--;
		nb /= 10;
	}
	return (str);
}

int	ft_print_unsigned_nb(unsigned int n)
{
	int		len;
	char	*number;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	number = ft_uitoa(n);
	len = ft_printstr(number);
	free(number);
	return (len);
}
