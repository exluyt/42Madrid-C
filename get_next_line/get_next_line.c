/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:15:13 by akiss             #+#    #+#             */
/*   Updated: 2024/10/03 11:20:23 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	int		capacity;

	capacity = BUFFER_SIZE + 1;
	i = 0;
	line = malloc(capacity);
	if (!line)
		return (NULL);
	if (ft_read_line(fd, line, &capacity) == NULL)
	{
		return (NULL);
	}
	return (line);
}
/* 
#include <stdio.h>
int main(int argc, char **argv)
{
	int fd;
	char *line;

	// Si no se pasan argumentos, usar stdin
	if (argc == 1) {
		fd = STDIN_FILENO;
	} else {
		// Intentar abrir el archivo proporcionado como argumento
		fd = open(argv[1], O_RDONLY);
		if (fd == -1) {
			perror("Error al abrir el archivo");
			return EXIT_FAILURE;
		}
	}

	// Leer y imprimir líneas hasta que no haya más
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line); // Liberar la memoria asignada por get_next_line
	}
	free(line); // Liberar la memoria asignada para la última línea

	// line = get_next_line(fd);
	// printf("%s", line);

	if (argc > 1) {
		close(fd); // Cerrar el archivo si se abrió uno
	}

	return EXIT_SUCCESS;
}
 */