/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:50:14 by akiss             #+#    #+#             */
/*   Updated: 2024/09/20 09:52:21 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(int nb, int fd)
{
	unsigned int		num;
	char				digit_char;
	char				last_digit_char;

	if (nb < 0)
	{
		write(fd, "-", 1);
		num = -nb;
	}
	else
	{
		num = nb;
	}
	if (num < 10)
	{
		digit_char = num + '0';
		write(fd, &digit_char, 1);
	}
	else
	{
		ft_putnbr(num / 10, fd);
		last_digit_char = num % 10 + '0';
		write(fd, &last_digit_char, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
