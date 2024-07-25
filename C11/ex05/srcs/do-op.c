/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:22:41 by akiss             #+#    #+#             */
/*   Updated: 2024/07/23 20:21:06 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_add(int num1, int num2);
int	ft_sub(int num1, int num2);
int	ft_mul(int num1, int num2);
int	ft_div(int num1, int num2);
int	ft_mod(int num1, int num2);

void	ft_putnbr(int nb)
{
	unsigned int		num;
	char				digit_char;
	char				last_digit_char;

	if (nb < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		num = -nb;
	}
	else
	{
		num = nb;
	}
	if (num < 10)
	{
		digit_char = num + '0';
		write(STDOUT_FILENO, &digit_char, 1);
	}
	else
	{
		ft_putnbr(num / 10);
		last_digit_char = num % 10 + '0';
		write(STDOUT_FILENO, &last_digit_char, 1);
	}
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void	ft_do_op(int num1, int (*f)(int, int), int num2)
{
	ft_putnbr(f(num1, num2));
}

int	main(int argc, char *argv[])
{
	int	num1;
	int	num2;

	if (argc != 4)
		return (0);
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	if (num2 == 0 && !ft_strcmp(argv[2], "/"))
		write(1, "Stop : division by zero\n", 24);
	else if (num2 == 0 && !ft_strcmp(argv[2], "%"))
		write(1, "Stop : modulo by zero\n", 23);
	else if (ft_strcmp(argv[2], "+") == 0)
		ft_do_op(num1, ft_add, num2);
	else if (ft_strcmp(argv[2], "-") == 0)
		ft_do_op(num1, ft_sub, num2);
	else if (ft_strcmp(argv[2], "*") == 0)
		ft_do_op(num1, ft_mul, num2);
	else if (ft_strcmp(argv[2], "/") == 0)
		ft_do_op(num1, ft_div, num2);
	else if (ft_strcmp(argv[2], "%") == 0)
		ft_do_op(num1, ft_mod, num2);
	else
		write(1, "0\n", 2);
	return (0);
}
