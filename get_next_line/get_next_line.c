/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpico <arpico@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:27:38 by arpico            #+#    #+#             */
/*   Updated: 2024/10/08 21:14:42 by arpico           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*past_line;
	char		*nl;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!past_line)
		past_line = ft_strndup("", 0);
	past_line = ft_read_and_store(fd, past_line);
	if (!past_line)
		return (NULL);
	nl = ft_strchr(past_line, '\n');
	if (nl == NULL && *past_line == '\0')
	{
		free(past_line);
		past_line = NULL;
		return (NULL);
	}
	line = ft_extract_line(&past_line, nl);
	return (line);
}

char	*ft_handle_buffer(char *past_line, char *buffer, int bytes_read)
{
	char	*temp;

	buffer[bytes_read] = '\0';
	temp = past_line;
	past_line = ft_strjoin(past_line, buffer);
	free(temp);
	return (past_line);
}

char	*ft_read_and_store(int fd, char *past_line)
{
	char	*buffer;
	int		bytes_read;
	char	*nl;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	nl = ft_strchr(past_line, '\n');
	while (!nl)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(past_line);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		past_line = ft_handle_buffer(past_line, buffer, bytes_read);
		nl = ft_strchr(past_line, '\n');
	}
	free(buffer);
	return (past_line);
}

char	*ft_extract_line(char **past_line, char *nl)
{
	char	*line;
	char	*temp;

	if (nl != NULL)
	{
		line = ft_strndup(*past_line, nl - *past_line + 1);
		temp = *past_line;
		*past_line = ft_strndup(nl + 1, ft_strlen(nl + 1));
		free(temp);
	}
	else
	{
		line = ft_strndup(*past_line, ft_strlen(*past_line));
		free(*past_line);
		*past_line = NULL;
	}
	return (line);
}
