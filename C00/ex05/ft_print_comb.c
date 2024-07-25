/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:31:17 by akiss             #+#    #+#             */
/*   Updated: 2024/07/05 12:03:46 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combination(char hund, char tens, char uni, int is_last)
{
	char	buffer[5];

	buffer[0] = hund;
	buffer[1] = tens;
	buffer[2] = uni;
	if (!is_last)
	{
		buffer[3] = ',';
		buffer[4] = ' ';
		write(1, buffer, 5);
	}
	else
	{
		write(1, buffer, 3);
	}
}

void	ft_print_comb(void)
{
	char	hund;
	char	tens;
	char	uni;
	int		is_last;

	hund = '0';
	tens = '1';
	uni = '2';
	while (hund <= '7')
	{
		while (tens <= '8')
		{
			while (uni <= '9')
			{
				is_last = (hund == '7' && tens == '8' && uni == '9');
				print_combination(hund, tens, uni, is_last);
				uni++;
			}
			tens++;
			uni = tens + 1;
		}
		hund++;
		tens = hund + 1;
		uni = tens + 1;
	}
}
/*
int main(void) {
    ft_print_comb();
    return 0;
}
*/
