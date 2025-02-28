/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:19:35 by akiss             #+#    #+#             */
/*   Updated: 2024/07/10 18:44:30 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(char *buffer, int is_last)
{
	if (is_last)
		write(1, buffer, 5);
	else
		write(1, buffer, 7);
}

void	increment_comb(char *buffer)
{
	if (++buffer[4] > '9')
	{
		buffer[4] = '0';
		buffer[3]++;
	}
	if (buffer[3] > '9')
	{
		buffer[3] = '0';
		buffer[1]++;
	}
	if (buffer[1] > '9')
	{
		buffer[1] = '0';
		buffer[0]++;
	}
}

int	is_last_comb(char *buffer)
{
	return ((buffer[0] == '9' && buffer[1] == '8')
		&& (buffer[3] == '9' && buffer[4] == '9'));
}

int	is_valid_comb(char *buffer)
{
	return ((buffer[0] < buffer[3]) || ((buffer[0] == buffer[3])
			&& (buffer[1] < buffer[4])));
}

void	ft_print_comb2(void)
{
	char	buffer[7];

	buffer[0] = '0';
	buffer[1] = '0';
	buffer[2] = ' ';
	buffer[3] = '0';
	buffer[4] = '1';
	buffer[5] = ',';
	buffer[6] = ' ';
	while (1)
	{
		if (is_valid_comb(buffer))
			print_comb(buffer, is_last_comb(buffer));
		if (is_last_comb(buffer))
			break ;
		increment_comb(buffer);
	}
}
/*
int		main(void)
{
	ft_print_comb2();
	return (0);
}
*/
