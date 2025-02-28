/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:07:40 by akiss             #+#    #+#             */
/*   Updated: 2024/07/09 14:02:02 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	is_num;

	is_num = 0;
	i = 0;
	if (str[i] == '\0')
	{
		is_num = 1;
		return (is_num);
	}
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			is_num = 1;
		else
		{
			is_num = 0;
			return (is_num);
		}
		i++;
	}
	return (is_num);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "123456";
	printf("%d\n", ft_str_is_numeric(str));
	return 0;
}
*/