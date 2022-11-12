/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:21:58 by yoson             #+#    #+#             */
/*   Updated: 2022/11/12 20:28:07 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

static int	find_path_execve(char *cmd, char *paths[], char *argv[], char *envp[])
{
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			ft_perror(NULL, EXIT_FAILURE);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!path)
			ft_perror(NULL, EXIT_FAILURE);
		if (ft_strnstr(path, "//", ft_strlen(path)))
		{
			free(path);
			return (-1);
		}
		execve(path, argv, envp);
		free(path);
		i++;
	}
	return (-1);
}

static void	error_handler(char *cmd)
{
	int	exit_code;

	if (!ft_strchr(cmd, '/'))
		command_not_found(cmd);
	open(cmd, O_RDWR);
	if (errno == ENOENT)
		exit_code = 127;
	else if (errno == EISDIR)
		exit_code = 126;
	else
		exit_code = EXIT_FAILURE;
	ft_perror(cmd, exit_code);
}

void	execute(char *arg, char *envp[], char *paths[])
{
	char	**argv;

	argv = ft_split(arg, ' ');
	if (!argv)
		ft_perror(NULL, EXIT_FAILURE);
	if (execve(argv[0], argv, envp) == -1)
	{
		if (find_path_execve(argv[0], paths, argv, envp) == -1)
			error_handler(argv[0]);
	}
}
