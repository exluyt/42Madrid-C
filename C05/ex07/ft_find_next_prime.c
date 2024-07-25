/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:41:11 by akiss             #+#    #+#             */
/*   Updated: 2024/07/11 11:19:52 by akiss            ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 0)
		return (ft_find_next_prime(nb + 1));
	else
		return (nb);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_find_next_prime(14));
	return (0);
}
*/