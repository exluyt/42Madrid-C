/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:53:04 by akiss             #+#    #+#             */
/*   Updated: 2024/07/10 07:50:44 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
/*
#include <stdlib.h>

int main()
{
    char *dest = malloc(50); // Asegura suficiente espacio
    char *src = " World!";

    // Asegúrate de inicializar dest con una cadena base.
    dest[0] = 'H';
    dest[1] = 'e';
    dest[2] = 'l';
    dest[3] = 'l';
    dest[4] = 'o';
    dest[5] = '\0';

    ft_strcat(dest, src);
    return 0;
}
*/