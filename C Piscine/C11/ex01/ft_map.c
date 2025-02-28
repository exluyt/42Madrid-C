/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:52:42 by akiss             #+#    #+#             */
/*   Updated: 2024/09/20 08:57:38 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*map;

	i = 0;
	map = (int *)malloc (sizeof(int) * length);
	if (map == NULL)
		return (NULL);
	while (i < length)
	{
		map[i] =f(tab[i]);
		i++;
	}
	return (map);
}
/* 
#include <stdio.h>
#include <stdlib.h>

// Una función simple para duplicar un número
int double_number(int n)
{
    return n * 2;
}

int main(void)
{
    int tab[] = {1, 2, 3, 4, 5}; // Arreglo de ejemplo
    int length = sizeof(tab) / sizeof(tab[0]); // Calcular el tamaño del arreglo
    int *result = ft_map(tab, length, double_number); 

    // Imprimir el resultado
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", result[i]);
    }

    free(result); // Liberar la memoria asignada por ft_map
    return 0;
}
 */
