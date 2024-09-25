/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:24:38 by akiss             #+#    #+#             */
/*   Updated: 2024/09/20 10:32:39 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

/*
#include <stdio.h>
int main ()
{
	// Test the ft_isascii function
	char test_char = 'A';
	if (ft_ascii(test_char))
		printf("%c is an ASCII character.\n", test_char);
	else
		printf("%c is not an ASCII character.\n", test_char);

	return 0;
}
*/