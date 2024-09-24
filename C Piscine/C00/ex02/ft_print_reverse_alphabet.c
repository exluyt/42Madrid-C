/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:47:30 by akiss             #+#    #+#             */
/*   Updated: 2024/07/05 21:14:00 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	*alphabet;

	alphabet = "zyxwvutsrqponmlkjihgfedcba";
	write (1, alphabet, 26);
}
/*
int main (void)
{
	ft_print_reverse_alphabet();
	return 0;
}
*/
