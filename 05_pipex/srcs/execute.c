/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:21:58 by yoson             #+#    #+#             */
/*   Updated: 2022/10/30 19:15:52 by yoson            ###   ########.fr       */
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

static char	*find_path(char *cmd, char *paths[])
{
	char	*path;
	char	*temp;
	int		i;

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

void	execute(char *arg, char *envp[], char *paths[])
{
	char	**argv;
	char	*path;

	arg = remove_directory_path(arg);
	argv = ft_split(arg, ' ');
	if (!argv)
		ft_perror();
	path = find_path(argv[0], paths);
	if (!path)
		ft_error("Error: command not found", 127);
	if (execve(path, argv, envp) == -1)
		ft_perror();
}
