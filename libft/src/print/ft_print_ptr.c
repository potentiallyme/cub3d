/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:28:19 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/18 16:19:22 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static unsigned int	ft_ptr_size(unsigned long long n)
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

static void	ft_print_adress(unsigned long long n, char *base)
{
	if (n >= 16)
	{
		ft_print_adress((n / 16), base);
		ft_putchar_fd(base[n % 16], 1);
	}
	else
	{
		ft_putchar_fd(base[n % 16], 1);
	}
}

int	ft_printptr(unsigned long long n)
{
	unsigned int	len;
	char			*base;

	base = "0123456789abcdef";
	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = ft_ptr_size(n);
	write(1, "0x", 2);
	ft_print_adress(n, base);
	len += 2;
	return (len);
}
