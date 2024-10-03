// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line_utils.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/30 10:15:17 by akiss             #+#    #+#             */
// /*   Updated: 2024/09/30 13:54:05 by akiss            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// char *get_next_line(int fd)
// {
//     char *line;
//     static char buffer[1]; // Asumiendo BUFFER_SIZE de 1 para simplificar
//     int i = 0;
//     int capacity = BUFFER_SIZE + 1; // Capacidad inicial de line

//     line = malloc(capacity);
//     if (!line)
//         return (NULL);

//     while (read(fd, buffer, 1) > 0)
//     {
//         if (i >= capacity - 1) // Necesitamos más espacio
//         {
//             capacity *= 2; // Duplicamos la capacidad
//             char *new_line = realloc(line, capacity);
//             if (!new_line)
//             {
//                 free(line); // No olvides liberar la memoria si realloc falla
//                 return (NULL);
//             }
//             line = new_line;
//         }
//         line[i++] = buffer[0];
//         if (buffer[0] == '\n')
//             break;
//     }

//     if (i == 0) // No se leyó nada
//     {
//         free(line);
//         return (NULL);
//     }

//     line[i] = '\0'; // Aseguramos que la cadena esté terminada correctamente
//     return (line);
// }

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	int fd;
// 	char *line;

// 	// Si no se pasan argumentos, usar stdin
// 	if (argc == 1) {
// 		fd = STDIN_FILENO;
// 	} else {
// 		// Intentar abrir el archivo proporcionado como argumento
// 		fd = open(argv[1], O_RDONLY);
// 		if (fd == -1) {
// 			perror("Error al abrir el archivo");
// 			return EXIT_FAILURE;
// 		}
// 	}

// 	// Leer y imprimir líneas hasta que no haya más
// 	while ((line = get_next_line(fd)) != NULL) {
// 		printf("%s", line);
// 		free(line); // Liberar la memoria asignada por get_next_line
// 	}
// 	// line = get_next_line(fd);
// 	// printf("%s", line);

// 	if (argc > 1) {
// 		close(fd); // Cerrar el archivo si se abrió uno
// 	}

// 	return EXIT_SUCCESS;
// }