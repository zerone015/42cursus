/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 03:18:02 by yoson             #+#    #+#             */
/*   Updated: 2023/02/07 02:36:23 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

void	first_child_process(char *argv[], char *envp[], int fd[], char *paths[])
{
	char	*limiter;
	int		infile;
	int		i;

	if (is_heredoc(argv[1]))
	{
		limiter = ft_strjoin(argv[2], "\n");
		if (!limiter)
			ft_perror(NULL, EXIT_FAILURE);
		here_doc(limiter);
		free(limiter);
		i = 3;
	}
	else
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
			ft_perror(argv[1], EXIT_FAILURE);
		i = 2;
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(argv[i], envp, paths);
}

void	last_child_process(char *argv[], int argc, char *envp[], char *paths[])
{
	int	fd;

	if (is_heredoc(argv[1]))
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 00644);
	else
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		ft_perror(argv[argc - 1], EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execute(argv[argc - 2], envp, paths);
}

void	child_process(char *arg, char *envp[], int fd[], char *paths[])
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(arg, envp, paths);
}

void	parent_process(int fd[])
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}

void	pipex(int argc, char *argv[], char *envp[], char *paths[])
{
	pid_t	pid;
	int		fd[2];
	int		i;

	i = 1 + is_heredoc(argv[1]);
	while (++i < argc - 1)
	{
		if (pipe(fd) == -1)
			ft_perror(NULL, EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			ft_perror(NULL, EXIT_FAILURE);
		else if (pid == 0)
		{
			if (i == 2 || (i == 3 && is_heredoc(argv[1])))
				first_child_process(argv, envp, fd, paths);
			if (i == argc - 2)
				last_child_process(argv, argc, envp, paths);
			child_process(argv[i], envp, fd, paths);
		}
		parent_process(fd);
	}
	while (wait(NULL) != -1)
		;
}
