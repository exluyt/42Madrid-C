/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:50:31 by akiss             #+#    #+#             */
/*   Updated: 2024/07/05 22:14:19 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combination(int num[], int n, int is_last)
{
	char	buffer[11];
	int		index;
	int		i;

	index = 0;
	i = 0;
	while (i < n)
	{
		buffer[index++] = num[i] + '0';
		i++;
	}
	if (!is_last)
	{
		buffer[index++] = ',';
		buffer[index++] = ' ';
	}
	write(1, buffer, index);
}

void	generate_combinations(int num[], int n, int index, int start)
{
	int		is_last;

	if (index == n)
	{
		is_last = (num[0] == 10 - n);
		print_combination(num, n, is_last);
		return ;
	}
	if (start <= 9)
	{
		num[index] = start;
		generate_combinations(num, n, index + 1, start + 1);
		generate_combinations(num, n, index, start + 1);
	}
}

void	ft_print_combn(int n)
{
	int		num[10];

	if (n <= 0 || n >= 10)
	{
		return ;
	}
	generate_combinations(num, n, 0, 0);
}
/*
int	main(void)
{
	ft_print_combn(9);
	return (0);
}
*/
