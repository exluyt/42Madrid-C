/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:42:30 by akiss             #+#    #+#             */
/*   Updated: 2024/07/09 13:59:09 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		is_alpha;

	is_alpha = 0;
	i = 0;
	if (str[i] == '\0')
	{
		is_alpha = 1;
		return (is_alpha);
	}
	while (str[i] != '\0')
	{
		if (('A' <= str[i] && str[i] <= 'Z')
			|| ('a' <= str[i] && str[i] <= 'z'))
			is_alpha = 1;
		else
		{
			is_alpha = 0;
			return (is_alpha);
		}
		i++;
	}
	return (is_alpha);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "Hello";
	printf("%d\n", ft_str_is_alpha(str));
	return 0;
}
*/