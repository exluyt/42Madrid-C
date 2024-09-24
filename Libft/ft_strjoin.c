/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:43:57 by akiss             #+#    #+#             */
/*   Updated: 2024/09/19 10:45:55 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc((len) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	i = 0;
	ft_strlcat(str, s1, len);
	ft_strlcat(str, s2, len);
	return (str);
}

/* 
#include <stdio.h>
#include <string.h>
int main ()
{
	char *s1 = "Hola";
	char *s2 = "Mundo";
	char *s3 = ft_strjoin(s1, s2);
	printf("%s\n", s3);
	return 0;
}
 */