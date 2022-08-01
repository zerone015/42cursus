/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 03:18:02 by yoson             #+#    #+#             */
/*   Updated: 2022/08/01 20:39:09 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void	child_process(char *argv, char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error(0, 0, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		error(0, 0, EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, WNOHANG);
	}
}

void	read_and_write(char *limiter, int fd[])
{
	char	*line;

	limiter = ft_strjoin(limiter, "\n");
	if (!limiter)
		error(0, 0, EXIT_FAILURE);
	line = get_next_line(STDIN_FILENO);
	if (!line)
		error(0, 0, EXIT_FAILURE);
	while (ft_strncmp(line, limiter, ft_strlen(line)) != 0)
	{
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			error(0, 0, EXIT_FAILURE);
	}
	free(line);
}

void	here_doc(char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];

	if (argc < 6)
		error(0, 0, EXIT_FAILURE);
	if (pipe(fd) == -1)
		error(0, 0, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		error(0, 0, EXIT_FAILURE);
	if (pid == 0)
	{
		read_and_write(limiter, fd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	pipex(int argc, char *argv[], char *envp[])
{
	int	i;
	int	infile;
	int	outfile;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		here_doc(argv[2], argc);
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 00644);
	}
	else
	{
		i = 2;
		infile = open(argv[1], O_RDONLY);
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 00644);
		dup2(infile, STDIN_FILENO);
	}
	if (outfile == -1)
		error(argv[argc - 1], strerror(errno), EXIT_FAILURE);
	while (i < argc - 2)
		child_process(argv[i++], envp);
	dup2(outfile, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
}
