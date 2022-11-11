/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:21:58 by yoson             #+#    #+#             */
/*   Updated: 2022/11/12 04:11:53 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

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
			ft_perror(NULL, EXIT_FAILURE);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!path)
			ft_perror(NULL, EXIT_FAILURE);
		if (ft_strnstr(path, "//", ft_strlen(path)))
		{
			free(path);
			return (NULL);
		}
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
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
	char	*path;

	argv = ft_split(arg, ' ');
	if (!argv)
		ft_perror(NULL, EXIT_FAILURE);
	if (execve(argv[0], argv, envp) == -1)
	{
		path = find_path(argv[0], paths);
		if (!path)
			error_handler(argv[0]);
	}
	if (execve(path, argv, envp) == -1)
		ft_perror(argv[0], EXIT_FAILURE);
}
