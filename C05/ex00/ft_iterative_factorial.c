/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:08:54 by akiss             #+#    #+#             */
/*   Updated: 2024/07/11 09:57:59 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		while (nb > 1)
		{
			result *= nb;
			nb--;
		}
	}
	return (result);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_iterative_factorial(5));
	return (0);
}
*/