/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:39:28 by akiss             #+#    #+#             */
/*   Updated: 2024/09/23 11:29:59 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

void	ft_putaddr_fd(unsigned long long number, int fd);
void	ft_puthex_lo_fd(unsigned long long number, int fd);
void	ft_puthex_up_fd(unsigned long long number, int fd);

void	ft_format(va_list args, const char *format)
{
	if (*format == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*format == 'p')
		ft_putaddr_fd(va_arg(args, unsigned long long), 1);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*format == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (*format == 'x')
		ft_puthex_lo_fd(va_arg(args, unsigned int), 1);
	else if (*format == 'X')
		ft_puthex_up_fd(va_arg(args, unsigned int), 1);
	else
		ft_putchar_fd(*format, 1);
}

int	ft_printf(char const *format, ...)
{
	va_list		args;

	va_start(args, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(args, format);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

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
