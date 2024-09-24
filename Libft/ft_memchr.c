/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr(por hacer).c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:22:14 by akiss             #+#    #+#             */
/*   Updated: 2024/09/18 13:44:47 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*schr;
	size_t			i;

	i = 0;
	schr = (unsigned char *)s;
	while (i < n)
	{
		if (*schr == (unsigned char)c)
		{
			return (schr);
		}
		schr++;
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main() {
    char str[] = "example string";
    char ch = 'e';
    unsigned char *result;

    // Using the custom ft_memchr function
    result = ft_memchr(str, ch, strlen(str));
    if (result != NULL)
        printf("Custom ft_memchr: Character found: %c\n", *result);
    else
        printf("Custom ft_memchr: Character not found\n");

    // Using the original memchr function
    result = memchr(str, ch, strlen(str));
    if (result != NULL)
        printf("Original memchr: Character found: %c\n", *result);
    else
        printf("Original memchr: Character not found\n");

    return 0;
}
*/