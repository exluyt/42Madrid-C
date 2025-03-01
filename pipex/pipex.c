/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:26:29 by akiss             #+#    #+#             */
/*   Updated: 2025/03/01 19:14:57 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	error_fd(int *fd, int number_fds)
{
	perror("Error");
	if (number_fds == 1)
		close(fd[0]);
	else if (number_fds == 2)
	{
		close(fd[0]);
		close(fd[1]);
	}
	exit(EXIT_FAILURE);
}

void	process_parent(char **argv, char **envp, int *fd)
{
	int	file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		error_fd(fd, 2);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	dup2(file, STDOUT_FILENO);
	close(file);
	exec(argv[3], envp);
}

void	process_child(char **argv, char **envp, int *fd)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		error_fd(fd, 2);
	dup2(file, STDIN_FILENO);
	close(file);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	exec(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error_fd(fd, 2);
		pid = fork();
		if (pid == -1)
			error_fd(fd, 2);
		if (pid == 0)
			process_child(argv, envp, fd);
		pid2 = fork();
		if (pid2 == -1)
			error_fd(fd, 2);
		if (pid2 == 0)
			process_parent(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
