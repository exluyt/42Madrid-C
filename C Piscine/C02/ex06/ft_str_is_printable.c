/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:40:19 by akiss             #+#    #+#             */
/*   Updated: 2024/07/09 14:02:37 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	is_printable;

	is_printable = 0;
	i = 0;
	if (str[i] == '\0')
	{
		is_printable = 1;
		return (is_printable);
	}
	while (str[i] != '\0')
	{
		if (32 <= str[i] && str[i] <= 126)
			is_printable = 1;
		else
		{
			is_printable = 0;
			return (is_printable);
		}
		i++;
	}
	return (is_printable);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "Hello";
	printf("%d\n", ft_str_is_printable(str));
	return 0;
}
*/