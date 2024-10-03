/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:57:42 by akiss             #+#    #+#             */
/*   Updated: 2024/10/03 11:19:39 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *line, int *capacity)
{
	char	buffer[1];
	int		i;

	i = 0;
	while (read(fd, buffer, 1) > 0)
	{
		if (i >= *capacity - 1)
		{
			*capacity *= 2;
			line = ft_realloc(line, *capacity);
			if (line == NULL)
				return (NULL);
		}
		line[i++] = buffer[0];
		if (buffer[0] == '\n')
			break ;
	}
	if (line[i])
		line[i] = '\0';
	if (i <= 0)
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

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
