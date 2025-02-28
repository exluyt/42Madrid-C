/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:20:56 by akiss             #+#    #+#             */
/*   Updated: 2024/09/30 09:17:12 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_sep(char c, char sep)
{
	return (c == sep || c == '\0');
}

static int	c_words(const char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (char_sep(str[i + 1], sep) && !char_sep(str[i], sep))
			words++;
		i++;
	}
	return (words);
}

static void	put_word(char *dest, const char *src, char sep)
{
	int	i;

	i = 0;
	while (!char_sep(src[i], sep))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	put_split(char **split, const char *str, char sep)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (char_sep(str[i], sep))
			i++;
		else
		{
			j = 0;
			while (!char_sep(str[i + j], sep))
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			put_word(split[word], str + i, sep);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	words = c_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = 0;
	put_split(split, s, c);
	return (split);
}


#include <stdio.h>
#include <stdlib.h>
int main() {
	char **result;
	char const *str = "";
	char sep = 'z';
	int i;

	result = ft_split(str, sep);
	i = 0;
	while (result[i] != NULL) {
		printf("Split[%d]: %s\n", i, result[i]);
		free(result[i]); // Free each string
		i++;
	}
	free(result); // Free the array of strings

	return 0;
}
