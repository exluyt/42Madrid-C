/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:31:21 by akiss             #+#    #+#             */
/*   Updated: 2024/07/09 14:02:15 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	is_lower;

	is_lower = 0;
	i = 0;
	if (str[i] == '\0')
	{
		is_lower = 1;
		return (is_lower);
	}
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
			is_lower = 1;
		else
		{
			is_lower = 0;
			return (is_lower);
		}
		i++;
	}
	return (is_lower);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "hello";
	printf("%d\n", ft_str_is_lowercase(str));
	return 0;
}
*/