/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 00:58:06 by akiss             #+#    #+#             */
/*   Updated: 2024/07/10 08:13:23 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
#include <stdio.h>
int main()
{
	char *s1;
	char *s2;
	int result= 0;
	
	s1 = "a";
	s2 = "c";
	result=ft_strcmp(s1, s2);
	printf("s1: %s, s2: %s, result: %d\n", s1, s2, result);
	return (0);
}
*/