/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:21:50 by akiss             #+#    #+#             */
/*   Updated: 2024/07/10 08:15:25 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
	char *s1;
	char *s2;
	int result= 0;
	int result2= 0;
	
	s1 = "ABC";
	s2 = "ABCD";
	result=ft_strncmp(s1, s2, 2);
	result2 = strncmp(s1, s2, 2);
	printf("s1: %s, s2: %s, result: %d, result2: %d\n", s1, s2, result, result2);
	return (0);

}
*/