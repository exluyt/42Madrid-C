/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:48:29 by akiss             #+#    #+#             */
/*   Updated: 2024/07/03 18:20:41 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	*digits;

	digits = "0123456789";
	write (1, digits, 10);
}
/*
int main ()
{
	ft_print_numbers();
	return 0;
}
*/
