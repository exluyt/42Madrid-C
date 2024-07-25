/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:54:41 by akiss             #+#    #+#             */
/*   Updated: 2024/07/16 11:20:03 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	j = 0;
	while (base[len] != '\0')
		len++;
	if (len <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	prepare_string_and_check_base(char **str, char *base, int *sign)
{
	int	i;

	i = 0;
	if (!check_base(base))
		return (0);
	while ((*str)[i] == ' ' || ((*str)[i] >= '\t' && (*str)[i] <= '\r'))
		i++;
	while ((*str)[i] == '-' || (*str)[i] == '+')
	{
		if ((*str)[i] == '-')
			*sign *= -1;
		i++;
	}
	*str += i;
	return (1);
}

int	convert_str_to_base(char *str, char *base, int sign)
{
	int	result;
	int	pos;
	int	base_len;

	result = 0;
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	while (*str != '\0')
	{
		pos = 0;
		while (base[pos] != '\0')
		{
			if (base[pos] == *str)
				break ;
			pos++;
		}
		if (pos == base_len)
			break ;
		result = result * base_len + pos;
		str++;
	}
	return (result * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;

	sign = 1;
	if (!prepare_string_and_check_base(&str, base, &sign))
		return (0);
	result = convert_str_to_base(str, base, sign);
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*base = "0123456789";
	char	*str = "  -+--1234";
	int		result;

	result = ft_atoi_base(str, base);
	printf("%d\n", result);
	return (0);
}
*/