/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:47:45 by akiss             #+#    #+#             */
/*   Updated: 2024/07/07 11:30:37 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
char	get_char(int row, int column, int x, int y);
void	err_invalid_nbr(void);

void	rush(int x, int y)
{
	int		row;
	int		column;

	if (x <= 0 || y <= 0)
	{
		err_invalid_nbr();
		return ;
	}
	row = 0;
	while (row < y)
	{
		column = 0;
		while (column < x)
		{
			ft_putchar(get_char(row, column, x, y));
			column++;
		}
		row++;
		ft_putchar('\n');
	}
}

char	get_char(int row, int column, int x, int y)
{
	if ((row == 0 && column == 0)
		|| (row == y - 1 && column == x - 1 && x > 1 && y > 1))
		return ('o');
	else if ((row == 0 && column == x - 1)
		|| (row == y - 1 && column == 0))
		return ('o');
	else if (row == 0 || row == y - 1)
		return ('-');
	else if (column == 0 || column == x - 1)
		return ('|');
	else
		return (' ');
}

/*
Functions that prints an error message with ANSI code to print it red.
*/
void	err_invalid_nbr(void)
{
	char	*error_msg;

	error_msg = "\033[1;31mError: Una figura geométrica no"
		" puede tener una longitud de 0 o negativa.\033[0m";
	write(1, error_msg, 81);

}
