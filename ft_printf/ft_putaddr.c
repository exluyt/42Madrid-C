/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:37:59 by akiss             #+#    #+#             */
/*   Updated: 2024/09/26 10:17:18 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffer_number(unsigned long long number,
int radix, int buffer[], int index) {
	if (number > (unsigned long long)(radix - 1))
		ft_buffer_number(number / radix, radix, buffer, index + 1);
	buffer[index] = number % radix;
}

int	ft_putaddr(unsigned long long number, int fd)
{
	int	buffer[16];
	int	index;
	int	size;

	size = 0;
	index = -1;
	while (++index < 16)
		buffer[index] = 0;
	ft_buffer_number(number, 16, buffer, 0);
	size += write(fd, "0x", 2);
	index = 16;
	while (index >= 0 && buffer[index] == 0)
		index--;
	if (index < 0)
		size += write(fd, "0", 1);
	else
		while (index >= 0)
			size += write(fd, &"0123456789abcdef"[buffer[index--]], 1);
	return (size);
}
