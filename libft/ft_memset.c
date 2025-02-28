/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:38:34 by akiss             #+#    #+#             */
/*   Updated: 2024/09/18 10:16:47 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* 
#include <stdio.h>
#include <string.h>
int main()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore memset(): %s\n", str);
	ft_memset(str, '.', 8);
	printf("After memset():  %s\n", str);
	char str1[50] = "GeeksForGeeks is for programming geeks.";
	memset(str1, '.', 8);
	printf("After memset():  %s\n", str1);
	return 0;
}
 */