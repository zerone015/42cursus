/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:18:57 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/05 00:15:07 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../includes/minishell.h"

char	*parse_cmd(char *argv)
{
	int	head;
	int	i;

	if (argv[ft_strlen(argv) - 1] == '/')
		return (argv);
	head = -1;
	i = 0;
	while (argv[i])
	{
		if (argv[i] == '/')
			head = i;
		i++;
	}
	head++;
	return (argv + head);
}

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

char	*find_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*path;
	char	*temp;
	int		i;
	int		fd;

	paths = parse_envp(envp);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		fd = open(path, O_RDONLY);
		if (fd != ERROR)
		{
			close(fd);
			return (path);
		}
		free(path);
	}
	return (NULL);
}

void	execute(char **argv, char **envp)
{
	char	*path;
	char	*cmd;

	cmd = argv[0];
	argv[0] = parse_cmd(argv[0]);
	path = find_path(argv[0], envp);
	if (is_directory(cmd))
		child_error("is a directory", cmd, 126);
	if (!path)
	{
		if (is_executable(cmd))
			path = cmd;
		else if (ft_strchr(cmd, '/'))
			child_error("No such file or directory", cmd, 127);
		else
			child_error("command not found", cmd, 127);
	}
	if (ft_strchr(cmd, '/') && !is_executable(cmd))
		child_error("No such file or directory", cmd, 127);
	if (execve(path, argv, envp) == -1)
		child_error(NULL, cmd, 1);
}
