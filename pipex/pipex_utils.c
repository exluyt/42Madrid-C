/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:23:31 by akiss             #+#    #+#             */
/*   Updated: 2025/03/01 19:18:19 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char	**ft_path(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	if (!envp[i])
		error();
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		error();
	return (paths);
}

void	exec(char *argv, char **envp)
{
	char	**args;
	char	**paths;
	char	*path;
	char	*cmd;
	int		i;

	args = ft_split(argv, ' ');
	if (!args || !args[0])
		error();
	paths = ft_path(envp);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(path, args[0]);
		free(path);
		if (access(cmd, X_OK) == 0)
		{
			execve(cmd, args, envp);
			free(cmd);
			break ;
		}
		free(cmd);
		i++;
	}
}
