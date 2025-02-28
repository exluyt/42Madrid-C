/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:49:10 by akiss             #+#    #+#             */
/*   Updated: 2024/09/17 10:17:39 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

/*
#include <stdio.h>
int main ()
{
	// Test the ft_isalpha function
	char test_char = 'ñ';
	if (ft_isalpha(test_char))
		printf("%c is an alphabetic character.\n", test_char);
	else
		printf("%c is not an alphabetic character.\n", test_char);

	return 0;
}
*/