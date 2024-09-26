/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:48:17 by akiss             #+#    #+#             */
/*   Updated: 2024/09/26 10:20:20 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int fd)
{
	unsigned int	num;
	int				size;

	size = 0;
	if (nb < 0)
	{
		size += write(fd, "-", 1);
		num = -nb;
	}
	else
	{
		num = nb;
	}
	if (num < 10)
	{
		size += write(fd, &(char){num + '0'}, 1);
	}
	else
	{
		size += ft_putnbr(num / 10, fd);
		size += write(fd, &(char){num % 10 + '0'}, 1);
	}
	return (size);
}
