/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:50:10 by akiss             #+#    #+#             */
/*   Updated: 2024/09/18 08:51:50 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/* 
#include <stdio.h>
int main ()
{
	// Test the ft_toupper function
	char test_char = '+';
	printf("Original character: %c\n", test_char);
	printf("Uppercase character: %c\n", ft_tolower(test_char));

	return 0;
}
 */