/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:25:14 by akiss             #+#    #+#             */
/*   Updated: 2024/07/10 13:03:38 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int		num;
	char				digit_char;
	char				last_digit_char;

	if (nb < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		num = -nb;
	}
	else
	{
		num = nb;
	}
	if (num < 10)
	{
		digit_char = num + '0';
		write(STDOUT_FILENO, &digit_char, 1);
	}
	else
	{
		ft_putnbr(num / 10);
		last_digit_char = num % 10 + '0';
		write(STDOUT_FILENO, &last_digit_char, 1);
	}
}

/*
#include <stdio.h>
int main()
{
	int num = -2147483648;
	ft_putnbr(num);
	return 0;
}
*/