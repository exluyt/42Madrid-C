/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:17:45 by akiss             #+#    #+#             */
/*   Updated: 2024/09/23 10:33:10 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_buffer_number(unsigned long long number,
int radix, int buffer[], int index)
{
	if (number > (unsigned long long)(radix - 1))
		ft_buffer_number(number / radix, radix, buffer, index + 1);
	buffer[index] = number % radix;
}

void	ft_putaddr_fd(unsigned long long number, int fd)
{
	int	buffer[16];
	int	index;

	index = 0;
	while (index < 16)
	{
		buffer[index] = 0;
		index++;
	}
	ft_buffer_number(number, 16, buffer, 0);
	write(fd, "0x", 2);
	index = 15;
	while (index >= 0 && buffer[index] == 0)
		index--;
	if (index < 0)
		write(fd, "0", 1);
	else
	{
		while (index >= 0)
		{
			write(fd, &"0123456789abcdef"[buffer[index]], 1);
			index--;
		}
	}
}
