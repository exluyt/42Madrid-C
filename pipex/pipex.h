/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:42:55 by akiss             #+#    #+#             */
/*   Updated: 2025/03/01 19:15:39 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <sys/types.h>
# include "ft_printf/ft_printf.h"
# include <sys/wait.h>
# include <fcntl.h>

void	exec(char *argv, char **envp);
void	error_fd(int *fd, int number_fds);
void	error(void);

#endif