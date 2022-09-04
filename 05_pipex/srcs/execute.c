/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:21:58 by yoson             #+#    #+#             */
/*   Updated: 2022/09/05 01:50:48 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>
#include <unistd.h>

char	*slash_ignore(char *argv)
{
	int	head;
	int	i;

	head = -1;
	i = 0;
	while (argv[i] && argv[i] != ' ')
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
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == NULL)
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

	paths = parse_envp(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (NULL);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!path)
			return (NULL);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	argv = slash_ignore(argv);
	cmd = ft_split(argv, ' ');
	if (!cmd)
		error(0, 0, EXIT_FAILURE);
	path = find_path(cmd[0], envp);
	if (!path)
		error(cmd[0], "command not found", 127);
	if (execve(path, cmd, envp) == -1)
		error(0, 0, EXIT_FAILURE);
}
