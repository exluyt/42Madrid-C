/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:31:28 by akiss             #+#    #+#             */
/*   Updated: 2024/07/23 13:15:38 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/* 
#include <stdio.h>
// Función de ejemplo para usar con ft_foreach
void	print_number(int n)
{
    printf("%d\n", n);
}

int	main(void)
{
    int	tab[] = {1, 2, 3, 4, 5}; // Arreglo de ejemplo
    int	length = sizeof(tab) / sizeof(tab[0]); // Calcular el tamaño del arreglo

    ft_foreach(tab, length, print_number); 

    return (0);
} 
*/
