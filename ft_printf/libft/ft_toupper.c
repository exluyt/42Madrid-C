/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:57:40 by akiss             #+#    #+#             */
/*   Updated: 2024/09/18 13:07:35 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/* 
#include <stdio.h>
int main ()
{
	// Test the ft_toupper function
	char test_char = 'a';
	printf("Original character: %c\n", test_char);
	printf("Uppercase character: %c\n", ft_toupper(test_char));

	return 0;
}
 */