/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:57:42 by akiss             #+#    #+#             */
/*   Updated: 2024/10/03 11:54:54 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_realloc_line(char *line, int *capacity)
{
	char	*new_line;
	int		i;

	new_line = malloc(sizeof(char) * (*capacity * 2));
	if (!new_line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	i = -1;
	while (++i < *capacity)
		new_line[i] = line[i];
	free(line);
	line = NULL;
	*capacity *= 2;
	return (new_line);
}

char	*ft_read_line(int fd, char *line, int *capacity)
{
	char	buffer[BUFFER_SIZE];
	int		i;

	i = 0;
	while (read(fd, buffer, 1) > 0)
	{
		if (i >= *capacity - 1)
		{
			line = ft_realloc_line(line, capacity);
			if (!line)
				return (NULL);
		}
		line[i++] = buffer[0];
		if (buffer[0] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
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
