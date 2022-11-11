/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:18:57 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/12 03:32:32 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "../includes/minishell.h"

char	**parse_envp(char *envp[])
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

int	find_path_execve(char *cmd, char *argv[], char *envp[])
{
	char	**paths;
	char	*path;
	char	*temp;
	int		i;

	paths = parse_envp(envp);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		execve(path, argv, envp);
		free(path);
	}
	return (ERROR);
}

static void	error_handler(char *cmd)
{
	int	exit_code;

	if (!ft_strchr(cmd, '/'))
		child_error("command not found", cmd, 127);
	open(cmd, O_RDWR);
	if (errno == ENOENT)
		exit_code = 127;
	else if (errno == EISDIR)
		exit_code = 126;
	else
		exit_code = EXIT_FAILURE;
	child_error(NULL, cmd, exit_code);
}

void	execute(char *argv[], char *envp[])
{
	char	*path;

	if (execve(argv[0], argv, envp) == ERROR)
	{
		if (find_path_execve(argv[0], argv, envp) == ERROR)
			error_handler(argv[0]);
	}
	if (execve(path, argv, envp) == ERROR)
		child_error(NULL, argv[0], EXIT_FAILURE);
}
