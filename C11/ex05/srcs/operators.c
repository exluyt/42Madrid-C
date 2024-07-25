/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:10:37 by akiss             #+#    #+#             */
/*   Updated: 2024/07/23 20:09:20 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_add(int num1, int num2)
{
	return (num1 + num2);
}

int	ft_sub(int num1, int num2)
{
	return (num1 - num2);
}

int	ft_mul(int num1, int num2)
{
	return (num1 * num2);
}

int	ft_div(int num1, int num2)
{
	return (num1 / num2);
}

int	ft_mod(int num1, int num2)
{
	return (num1 % num2);
}
