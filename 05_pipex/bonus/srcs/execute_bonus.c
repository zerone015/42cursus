/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:21:58 by yoson             #+#    #+#             */
/*   Updated: 2022/11/01 05:02:03 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

static char	*remove_directory_path(char *cmd)
{
	char	*ret;

	ret = cmd;
	while (*cmd && *cmd != ' ')
	{
		if (*cmd == '/')
			ret = ++cmd;
		else
			cmd++;
	}
	return (ret);
}

static char	*find_path(char *cmd, char *paths[])
{
	char	*path;
	char	*temp;
	int		i;

	if (*cmd == '\0')
		return (NULL);
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
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

static int	is_slash_contain(char *str)
{
	while (*str)
	{
		if (*str == '/')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

static void	error_handler(char *cmd)
{
	int	exit_code;

	if (!is_slash_contain(cmd))
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
		path = find_path(remove_directory_path(argv[0]), paths);
		if (!path)
			error_handler(argv[0]);
	}
	if (execve(path, argv, envp) == -1)
		ft_perror(argv[0], EXIT_FAILURE);
}
