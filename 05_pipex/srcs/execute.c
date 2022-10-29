/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:21:58 by yoson             #+#    #+#             */
/*   Updated: 2022/10/30 08:12:16 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>
#include <unistd.h>

static char	*remove_directory_path(char *arg)
{
	char	*ret;

	ret = arg;
	while (*arg && *arg != ' ')
	{
		if (*arg == '/')
			ret = ++arg;
		else
			arg++;
	}
	return (ret);
}

static char	**parse_envp(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

static char	*find_path(char *cmd, char *envp[])
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

void	execute(char *arg, char **envp)
{
	char	**argv;
	char	*path;

	arg = remove_directory_path(arg);
	argv = ft_split(arg, ' ');
	if (!argv)
		ft_perror();
	path = find_path(argv[0], envp);
	if (!path)
		ft_error("Error: command not found", 127);
	if (execve(path, argv, envp) == -1)
		ft_perror();
}
