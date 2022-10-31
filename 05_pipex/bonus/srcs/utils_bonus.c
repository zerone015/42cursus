/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:47:35 by yoson             #+#    #+#             */
/*   Updated: 2022/11/01 03:27:19 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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

int	redirection_stdin(char *argv[])
{
	char	*limiter;
	int		fd;
	int		idx;

	if (is_heredoc(argv[1]))
	{
		limiter = ft_strjoin(argv[2], "\n");
		if (!limiter)
			ft_perror(NULL, EXIT_FAILURE);
		here_doc(limiter);
		free(limiter);
		idx = 3;
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_perror(argv[1], EXIT_FAILURE);
		idx = 2;
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (idx);
}
