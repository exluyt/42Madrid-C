/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:02:06 by akiss             #+#    #+#             */
/*   Updated: 2024/07/10 04:59:49 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_alphanumeric(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_first;

	i = 0;
	is_first = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && is_first)
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z' && !is_first)
			str[i] += 32;
		is_first = !is_alphanumeric(str[i++]);
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(str));
	return 0;
}
*/