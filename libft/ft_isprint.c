/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:07:33 by akiss             #+#    #+#             */
/*   Updated: 2024/09/17 11:12:24 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

/*
#include <stdio.h>
int main ()
{
	// Test the ft_isprint function
	char test_char = ' ';
	if (ft_isprint(test_char))
		printf("%c is a printable character.\n", test_char);
	else
		printf("%c is not a printable character.\n", test_char);

	return 0;
}
*/