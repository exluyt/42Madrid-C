/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:39:28 by akiss             #+#    #+#             */
/*   Updated: 2024/09/26 11:39:28 by akiss            ###   ########.fr       */
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
		size += ft_putnbr_u(va_arg(args, unsigned int), 1);
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
	printf("NULL %s NULL", NULL);
	printf("\n");
	ft_printf("%c", 'A');
}
 */