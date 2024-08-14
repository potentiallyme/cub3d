/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:56 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/18 16:19:22 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static unsigned int	ft_hex_size(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_putnbr_hex(unsigned int n, const char *base)
{
	if (n >= 16)
	{
		ft_putnbr_hex((n / 16), base);
		ft_putchar_fd(base[n % 16], 1);
	}
	else
	{
		ft_putchar_fd(base[n % 16], 1);
	}
}

int	ft_printhex(unsigned int n, char format)
{
	unsigned int	len;
	char			*lower_base;
	char			*upper_base;

	lower_base = "0123456789abcdef";
	upper_base = "0123456789ABCDEF";
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = ft_hex_size(n);
	if (format == 'x')
		ft_putnbr_hex(n, lower_base);
	else
		ft_putnbr_hex(n, upper_base);
	return (len);
}
