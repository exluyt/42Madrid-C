/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:49:10 by akiss             #+#    #+#             */
/*   Updated: 2024/09/17 10:25:23 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (('0' <= c && c <= '9'));
}

/*
#include <stdio.h>
int main ()
{
	// Test the ft_isdigit function
	char test_char = '0';
	if (ft_isdigit(test_char))
		printf("%c is a digit character.\n", test_char);
	else
		printf("%c is not a digit character.\n", test_char);

	return 0;
}
*/