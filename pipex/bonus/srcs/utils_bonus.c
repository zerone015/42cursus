/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:47:35 by yoson             #+#    #+#             */
/*   Updated: 2023/02/07 02:21:09 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

char	**parse_paths(char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	if (!envp[i])
		ft_perror(NULL, EXIT_FAILURE);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		ft_perror(NULL, EXIT_FAILURE);
	return (paths);
}

int	is_heredoc(char *arg)
{
	if (ft_strncmp(arg, "here_doc", ft_strlen(arg)) == 0)
		return (TRUE);
	return (FALSE);
}

void	here_doc(char *limiter)
{
	int		fd;
	char	*line;

	fd = open("/tmp/.here_doc", O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		ft_perror("here_doc", EXIT_FAILURE);
	while (1)
	{
		ft_putstr_fd("> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || ft_strncmp(line, limiter, ft_strlen(line)) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	fd = open("/tmp/.here_doc", O_RDONLY);
	if (fd == -1)
	{
		unlink("/tmp/.here_doc");
		ft_perror("here_doc", EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
}
