/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:12:43 by akiss             #+#    #+#             */
/*   Updated: 2024/09/18 13:41:47 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*schr1;
	const unsigned char	*schr2;

	i = 0;
	schr1 = (const unsigned char *)s1;
	schr2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char)schr1[i] != (unsigned char)schr2[i])
		{
			return ((unsigned char)schr1[i] - (unsigned char)schr2[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main() {
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    char str3[] = "Hello, world!";

    // Comparando cadenas idénticas con ft_memcmp
    printf("ft_memcmp on identical strings: 
	%d\n", ft_memcmp(str1, str2, sizeof(str1)));
    // Comparando cadenas idénticas con memcmp
    printf("memcmp on identical strings: %d\n", 
	memcmp(str1, str2, sizeof(str1)));

    // Comparando cadenas diferentes con ft_memcmp
    printf("ft_memcmp on different strings: %d\n",
	 ft_memcmp(str1, str3, sizeof(str1)));
    // Comparando cadenas diferentes con memcmp
    printf("memcmp on different strings: %d\n", 
	memcmp(str1, str3, sizeof(str1)));

    return 0;
}
*/