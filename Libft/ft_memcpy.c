/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:15:47 by akiss             #+#    #+#             */
/*   Updated: 2024/09/25 11:03:32 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	char str1[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore memcpy(): %s\n", str);
	ft_memcpy(str + 13, str, 8);
	printf("After memcpy():  %s\n", str);
	printf("\nBefore memcpy(): %s\n", str1);
	memcpy(str1 + 13, str1, 8);
	printf("After memcpy():  %s\n", str1);
	return 0;
}
*/