/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:47:35 by yoson             #+#    #+#             */
/*   Updated: 2022/11/01 05:03:17 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

char	**parse_paths(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
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

int	wait_all(pid_t last_pid)
{
	pid_t	pid;
	int		temp;
	int		status;

	pid = 1;
	while (pid != -1)
	{
		pid = wait(&temp);
		if (pid == last_pid)
			status = temp;
	}
	return (status);
}
