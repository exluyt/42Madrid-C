/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:51:37 by akiss             #+#    #+#             */
/*   Updated: 2024/09/25 10:29:42 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy_back(unsigned char *d, const unsigned char *s, size_t n)
{
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
}

static void	cpy_for(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d > s)
		cpy_back(d, s, n);
	else
		cpy_for(d, s, n);
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char original[] = "Este es un ejemplo de texto.";
    char copia1[sizeof(original)];
    char copia2[sizeof(original)];

    // Usando la función original memmove
    memmove(copia1, original, sizeof(original));
    printf("Original memmove: %s\n", copia1);

    // Usando tu función ft_memmove
    ft_memmove(copia2, original, sizeof(original));
    printf("Tu ft_memmove: %s\n", copia2);

    return 0;
}
*/