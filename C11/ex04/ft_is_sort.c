/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:07:07 by akiss             #+#    #+#             */
/*   Updated: 2024/07/23 19:08:04 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}
/* 
#include <stdio.h>
int ft_sort(int a, int b)
{
	return (a - b);
}

int ft_sort_rev(int a, int b)
{
	return (b - a);
}

int main(void)
{
	int tab[] = {1, 2, 4, 5, 4}; // Arreglo de ejemplo
	int length = sizeof(tab) / sizeof(tab[0]); // Calcular el tamaño del arreglo

	printf("Is sort: %d\n", ft_is_sort(tab, length, ft_sort));
	printf("Is sort rev: %d\n", ft_is_sort(tab, length, ft_sort_rev));

	return (0);
}
 */