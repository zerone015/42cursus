/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 03:18:02 by yoson             #+#    #+#             */
/*   Updated: 2022/11/01 05:02:26 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

static void	child_process1(char *argv[], char *envp[], int fd[], char *paths[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_perror(argv[1], EXIT_FAILURE);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(argv[2], envp, paths);
}

static void	child_process2(char *argv[], char *envp[], int fd[], char *paths[])
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (outfile == -1)
		ft_perror(argv[4], EXIT_FAILURE);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	execute(argv[3], envp, paths);
}

static char	**parse_paths(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

void	pipex(char *argv[], char *envp[], char *paths[])
{
	pid_t	pid;
	int		fd[2];
	int		i;

	if (pipe(fd) == -1)
		ft_perror(NULL, EXIT_FAILURE);
	i = 1;
	while (++i < 4)
	{
		pid = fork();
		if (pid == -1)
			ft_strerror();
		if (pid == 0 && i == 2)
			child_process1(argv, envp, fd, paths);
		if (pid == 0 && i == 3)
			child_process2(argv, envp, fd, paths);
	}
	close(fd[0]);
	close(fd[1]);
	while (wait(NULL) != -1)
		;
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;

	if (argc < 5)
	{
		ft_putstr_fd("pipex: Too few arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (argc > 5)
	{
		ft_putstr_fd("pipex: Too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	paths = parse_paths(envp);
	if (!paths)
	{
		perror("pipex: ");
		return (EXIT_FAILURE);
	}
	pipex(argv, envp, paths);
	return (0);
}
