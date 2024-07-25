/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:24:15 by akiss             #+#    #+#             */
/*   Updated: 2024/07/10 08:16:17 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (j < nb && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *dest = malloc(50); // Asegura suficiente espacio
	char *src = " Worwerrld!";
	// Asegúrate de inicializar dest con una cadena base.
	dest[0] = 'H';
	dest[1] = 'e';
	dest[2] = 'l';
	dest[3] = 'l';
	dest[4] = 'o';
	dest[5] = '\0';

	// Duplica dest para usar con strncat después de ft_strncat
	char *destCopy = strdup(dest);

	// Usa tu función ft_strncat
	ft_strncat(dest, src, 0);
	printf("Con ft_strncat: %s\n", dest);

	// Usa la función original strncat
	strncat(destCopy, src, 0);
	printf("Con strncat: %s\n", destCopy);

	// Libera la memoria
	free(dest);
	free(destCopy);

	return 0;
}
*/