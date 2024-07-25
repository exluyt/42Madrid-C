/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:04:07 by akiss             #+#    #+#             */
/*   Updated: 2024/07/11 10:04:11 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		result *= nb;
		ft_recursive_power(nb, power - 1);
		power--;
	}
	return (result);
}
/*
#include <stdio.h>
int main ()
{
		printf("%d\n", ft_recursive_power(5, 3));
		return (0);
}
*/