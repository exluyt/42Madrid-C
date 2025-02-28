/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:24:31 by akiss             #+#    #+#             */
/*   Updated: 2024/07/16 19:53:15 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs(int x)
{
	if (x > 0)
		return (x);
	else
		return (-x);
}

int	is_safe(int pos[], int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (pos[i] == row || abs(i - col) == abs(pos[i] - row))
			return (0);
		i++;
	}
	return (1);
}

void	print_solution(int pos[])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = pos[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	try_row(int pos[], int col, int row, int *solutions)
{
	if (row >= 10)
		return ;
	if (is_safe(pos, col, row))
	{
		pos[col] = row;
		if (col == 9)
		{
			print_solution(pos);
			(*solutions)++;
		}
		else
			try_row(pos, col + 1, 0, solutions);
	}
	try_row(pos, col, row + 1, solutions);
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];
	int	solutions;

	solutions = 0;
	try_row(pos, 0, 0, &solutions);
	return (solutions);
}

#include <stdio.h>
#include <stdlib.h>
int main() {
	int total_solutions = ft_ten_queens_puzzle();
	char buffer[50];
	sprintf(buffer, "Total solutions: %d\n", total_solutions);
	write(1, buffer, 50);
	return 0;
}

