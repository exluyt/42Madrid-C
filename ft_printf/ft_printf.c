/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:39:28 by akiss             #+#    #+#             */
/*   Updated: 2024/09/26 10:08:07 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_format(va_list args, const char *format)
{
	int	size;

	size = 0;
	if (*format == 'c')
		size += ft_putchar(va_arg(args, int), 1);
	else if (*format == 's')
		size += ft_putstr(va_arg(args, char *), 1);
	else if (*format == 'p')
		size += ft_putaddr(va_arg(args, unsigned long long), 1);
	else if (*format == 'd' || *format == 'i')
		size += ft_putnbr(va_arg(args, int), 1);
	else if (*format == 'u')
		size += ft_putnbr(va_arg(args, unsigned int), 1);
	else if (*format == 'x')
		size += ft_puthex_lo_fd(va_arg(args, unsigned int), 1);
	else if (*format == 'X')
		size += ft_puthex_up_fd(va_arg(args, unsigned int), 1);
	else
		size += ft_putchar(*format, 1);
	return (size);
}

int	ft_printf(char const *format, ...)
{
	va_list		args;
	int			size;

	size = 0;
	va_start(args, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			size += ft_format(args, format);
		}
		else
			size += ft_putchar(*format, 1);
		format++;
	}
	va_end(args);
	return (size);
}

/* 
int	main(void)
{
	printf("%c", 'A');
	printf("\n");
	ft_printf("%c", 'A');
	
	printf("\n");
	printf("%s", "A b");
	printf("\n");
	ft_printf("%s", "A b");

	printf("\n");
	printf("%p", "Ar");
	printf("\n");
	ft_printf("%p", "Ar");

	printf("\n");
	printf("%d", 2);
	printf("\n");
	ft_printf("%d", 2);
	
	printf("\n");
	printf("%u", 5);
	printf("\n");
	ft_printf("%u", 5);
	
	printf("\n");
	printf("%x", 0x402015a);
	printf("\n");
	ft_printf("%x", 0x402015a);

	printf("\n");
	printf("%X", 0x402015a);
	printf("\n");
	ft_printf("%X", 0x402015a);
	printf("\n");
	
	printf("%%");
	printf("\n");
	ft_printf("%%");
	printf("\n");
	return (0);
}
 */
