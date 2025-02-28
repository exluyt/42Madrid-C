/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:52:36 by akiss             #+#    #+#             */
/*   Updated: 2024/09/17 13:48:30 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*dest;

	dest = s;
	i = 0;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

/* 
#include <stdio.h>
int main()
{
    char str[] = "Hello, World!";
    printf("Before ft_bzero: %s\n", str);
    ft_bzero(str, 6); // Zero out the first 6 characters
    printf("After ft_bzero: ");
    for (size_t i = 0; i < sizeof(str); i++) {
        if (str[i] == '\0')
            printf("\\0");
        else
            printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
 */