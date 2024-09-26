/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:36:33 by akiss             #+#    #+#             */
/*   Updated: 2024/09/26 11:37:38 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb, int fd)
{
	unsigned int	num;
	int				size;

	size = 0;
	num = nb;
	if (num < 10)
		size += write(fd, &(char){num + '0'}, 1);
	else
	{
		size += ft_putnbr_u(num / 10, fd);
		size += write(fd, &(char){num % 10 + '0'}, 1);
	}
	return (size);
}
