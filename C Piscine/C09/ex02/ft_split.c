/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:21:27 by akiss             #+#    #+#             */
/*   Updated: 2024/09/17 13:35:16 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	char_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	c_words(char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_sep(str[i + 1], charset) == 1
			&& char_sep(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	put_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (char_sep(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	put_split(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (char_sep(str[i + j], charset) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			put_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;

	words = c_words(str, charset);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	split[words] = 0;
	put_split(split, str, charset);
	return (split);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**split;
	int		i;

	split = ft_split("quesoquera", "que");
	i = 0;
	while (split[i] != 0)
	{
		printf("%s\n", split[i]);
		i++;
	}
	return (0);
}
*/