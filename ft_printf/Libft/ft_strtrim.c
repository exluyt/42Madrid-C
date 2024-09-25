/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:16:39 by akiss             #+#    #+#             */
/*   Updated: 2024/09/20 10:56:33 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, (end - start)));
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
	char const *s1 = "lorem ipsum dolor sit amet";
	char const *set = "te";
	char *trimmed_str;

	trimmed_str = ft_strtrim(s1, set);
	if (trimmed_str != NULL) {
		printf("Original string: '%s'\n", s1);
		printf("Trimmed string: '%s'\n", trimmed_str);
		free(trimmed_str);
	} else {
		printf("Error: Memory allocation failed.\n");
	}

	return 0;
}
*/