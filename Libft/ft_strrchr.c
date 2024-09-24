/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:11:49 by akiss             #+#    #+#             */
/*   Updated: 2024/09/18 09:23:40 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == '\0')
	{
		return ((char *)&s[len]);
	}
	while (len >= '\0')
	{
		if (s[len] == c)
		{
			return ((char *)&s[len]);
		}
		len--;
	}
	return (NULL);
}

/* 
#include <stdio.h>
int main ()
{
	// Test the ft_strrchr function
	char *test_string = "Hello, World!";
	char test_char = 'o';
	char *result = ft_strrchr(test_string, test_char);
	if (result)
		printf("Character %c found at position %ld.\n", 
		test_char, result - test_string);
	else
		printf("Character %c not found.\n", test_char);

	return 0;
}
 */