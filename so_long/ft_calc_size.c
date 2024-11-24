/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:43:24 by akiss             #+#    #+#             */
/*   Updated: 2024/11/24 16:42:36 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_calc_width(char *argv)
{
	int		fd;
	char	*line;
	int		width;

	width = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), EXIT_FAILURE);
	else
	{
		line = get_next_line(fd);
		while (line[width] != '\0')
			width++;
	}
	return (free(line), close(fd), get_next_line(-1), width - 1);
}

int	ft_calc_height(char *argv)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), EXIT_FAILURE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), height);
}
