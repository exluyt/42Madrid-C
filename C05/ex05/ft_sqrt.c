/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:07:43 by akiss             #+#    #+#             */
/*   Updated: 2024/07/13 18:10:42 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqr;

	sqr = 0;
	if (nb == 1)
		return (1);
	else if (nb >= 2)
	{
		while (sqr <= nb / 2)
		{
			if (sqr * sqr == nb)
			{
				return (sqr);
			}
			else
				sqr++;
		}
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_sqrt(4));
	return (0);
}
*/
