/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:26:35 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/18 16:19:22 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*number;

	len = 0;
	number = ft_itoa(n);
	len = ft_printstr(number);
	free(number);
	return (len);
}
