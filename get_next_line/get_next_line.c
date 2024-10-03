/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:15:13 by akiss             #+#    #+#             */
/*   Updated: 2024/10/03 11:44:40 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		capacity;

	capacity = BUFFER_SIZE + 1;
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
int main(int argc, char **argv) {
    int fd;
    char *line;

    // Si no se pasan argumentos, usar stdin
    if (argc == 1) {
        fd = STDIN_FILENO;
        while ((line = get_next_line(fd)) != NULL) {
            printf("%s", line);
            free(line);
        }
        free(line);
    } else {
        // Iterar sobre cada archivo proporcionado como argumento
        for (int i = 1; i < argc; i++) {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1) {
                perror("Error al abrir el archivo");
                continue;
            }

            // Leer y imprimir líneas hasta que no haya más
            while ((line = get_next_line(fd)) != NULL) {
                printf("%s", line);
                free(line);
            }
            free(line);

            close(fd); // Cerrar el archivo antes de pasar al siguiente
        }
    }

    return EXIT_SUCCESS;
}
*/