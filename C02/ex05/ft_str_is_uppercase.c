/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:37:16 by akiss             #+#    #+#             */
/*   Updated: 2024/07/09 14:02:30 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	is_upper;

	is_upper = 0;
	i = 0;
	if (str[i] == '\0')
	{
		is_upper = 1;
		return (is_upper);
	}
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			is_upper = 1;
		else
		{
			is_upper = 0;
			return (is_upper);
		}
		i++;
	}
	return (is_upper);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "HELLO";
	printf("%d\n", ft_str_is_uppercase(str));
	return 0;
}
*/