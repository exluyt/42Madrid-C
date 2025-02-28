/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:34:49 by akiss             #+#    #+#             */
/*   Updated: 2024/07/11 11:18:23 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	prime;

	prime = 2;
	if (nb <= 1)
		return (0);
	else
	{
		while (prime <= nb / 2)
		{
			if (nb % prime == 0)
				return (0);
			else
				prime++;
		}
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_is_prime(33));
	return (0);
}
*/
