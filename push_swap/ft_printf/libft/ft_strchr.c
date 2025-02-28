/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:52:38 by akiss             #+#    #+#             */
/*   Updated: 2024/09/25 11:11:42 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/* 
#include <stdio.h>
int main ()
{
	// Test the ft_strchr function
	char *test_string = "Hello, World!";
	char test_char = 'z';
	char *result = ft_strchr(test_string, test_char);
	if (result)
		printf("Character %c found at position %ld.\n", 
		test_char, result - test_string);
	else
		printf("Character %c not found.\n", test_char);

	return 0;
}
 */