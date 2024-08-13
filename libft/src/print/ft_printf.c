/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:15:36 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/18 16:19:22 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_parse(va_list args, const char format)
{
	int	count_char;

	count_char = 0;
	if (format == 'c')
		count_char += ft_printchar(va_arg(args, int));
	else if (format == 's')
		count_char += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		count_char += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd')
		count_char += ft_printnbr(va_arg(args, int));
	else if (format == 'i')
		count_char += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		count_char += ft_print_unsigned_nb(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count_char += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
	{
		write(1, "%", 1);
		count_char++;
	}
	return (count_char);
}

int	ft_printf(const char *txt, ...)
{
	int		i;
	va_list	args;
	int		count_char;

	i = 0;
	count_char = 0;
	va_start(args, txt);
	if (txt == NULL)
		return (-1);
	while (txt[i])
	{
		if (txt[i] == '%')
		{
			count_char += ft_parse(args, txt[i + 1]);
			i++;
		}
		else
			count_char += ft_printchar(txt[i]);
		i++;
	}
	va_end(args);
	return (count_char);
}

// int main() {

// 	char c = 'd';
// 	char str[] = "World";
// 	int	d = 10;
// 	int	i = 15;
// 	unsigned int u = 4294967295;
// 	unsigned long x = 0;
// 	unsigned long X = 47575;
// 	int a = 7496;
// 	int *p;
// 	p = &a;

// 	printf("\nTesting ft_printf with a single %%c arguments:\n");
// 	printf("\nft_printf returned: %d\n", ft_printf("Hello, worl%c!", c));

// 	printf("\nTesting ft_printf with a single %%s argument:\n");
// 	printf("ft_printf returned: %d\n", ft_printf("\nHello, %s!", str));

// 	printf("\nTesting ft_printf with a single %%d argument:\n");
// 	printf("ft_printf returned: %d\n", ft_printf("\nis 10 ? %d: ", d));

// 	printf("\nTesting ft_printf with a single %%i argument:\n");
// 	printf("ft_printf returned: %d\n", ft_printf("\nis 15 ? %i: ", i));

// 	printf("\nTesting ft_printf with a single %%u argument:\n");
// 	printf("\nft_printf returned: %d\n", ft_printf("is 4294966647 : %u", u));
// 	printf("Comparaison :");
// 	printf("\ntrue printf: %u\n", u);
// 	ft_printf("ft_printf: %u\n", u);

// 	ft_printf("ft_printf: %x\n", x);

// 	printf("\nTesting ft_printf with a single %%X maj argument:\n");
// 	printf("ft_printf returned: %d\n", ft_printf("\nis B9D7 ? %X ", X));
// 	printf("Comparaison :");
// 	printf("\ntrue printf: %lX\n", X);
// 	ft_printf("ft_printf: %X\n", X);

// 	printf("\ntrue printf: %p\n", (void *)3005);
// 	ft_printf("ft_printf: %p\n", (void *)3005);
// }