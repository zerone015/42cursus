/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 03:18:02 by yoson             #+#    #+#             */
/*   Updated: 2022/11/01 03:27:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

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

static void	child_process(char *arg, char *envp[], int fd[], char *paths[])
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(arg, envp, paths);
}

static void	parent_process(int fd[])
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

	i = 0;
	while (++i < argc - 1)
	{
		if (pipe(fd) == -1)
			ft_strerror();
		pid = fork();
		if (pid == -1)
			ft_strerror();
		else if (pid == 0)
		{
			if (i == 1)
				i = redirection_stdin(argv);
			if (i == argc - 2)
				last_child_process(argv, argc, envp, paths);
			child_process(argv[i], envp, fd, paths);
		}
		parent_process(fd);
	}
	while (wait(NULL) != -1)
		;
	unlink("/tmp/.here_doc");
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;

	if (argc < 5 || (is_heredoc(argv[1]) && argc < 6))
	{
		ft_putstr_fd("Error: Too few arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	paths = parse_paths(envp);
	if (!paths)
	{
		perror("pipex: ");
		return (EXIT_FAILURE);
	}
	pipex(argc, argv, envp, paths);
	return (0);
}
