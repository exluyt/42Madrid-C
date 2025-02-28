/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:28:31 by akiss             #+#    #+#             */
/*   Updated: 2024/09/20 12:49:43 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_numlen(int n)
{
	int	len;

	if (n <= 0)
	{
		len = 1;
	}
	else
	{
		len = 0;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		len--;
		str[len] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	return (str);
}

/*
int main(void)
{
	char *result;

	// Prueba con un número positivo
	result = ft_itoa(123);
	printf("123 -> %s\n", result);
	free(result); // Liberar la memoria asignada

	// Prueba con un número negativo
	result = ft_itoa(-456);
	printf("-456 -> %s\n", result);
	free(result);

	// Prueba con cero
	result = ft_itoa(0);
	printf("0 -> %s\n", result);
	free(result);

	// Prueba con el mínimo valor de un int
	result = ft_itoa(-2147483648);
	printf("-2147483648 -> %s\n", result);
	free(result);

	return 0;
}
*/