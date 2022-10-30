/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 03:18:02 by yoson             #+#    #+#             */
/*   Updated: 2022/10/30 09:20:30 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

static void	child_process(char *argv[], char *envp[], int fd[], int i, int argc)
{
	int	outfile;

	if (i == argc - 2)
	{
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 00644);
		if (outfile == -1)
			ft_perror();
		dup2(outfile, STDOUT_FILENO);
	}
	else
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(argv[i], envp);
}

static void	parent_process(int fd[])
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
}

void	pipex(char *argv[], char *envp[], int argc)
{
	pid_t	pid;
	int		infile;
	int		fd[2];
	int		i;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_perror();
	dup2(infile, STDIN_FILENO);
	close(infile);
	i = 1;
	while (++i < argc - 1)
	{
		if (pipe(fd) == -1)
			ft_strerror();
		pid = fork();
		if (pid == -1)
			ft_strerror();
		else if (pid == 0)
			child_process(argv, envp, fd, i, argc);
		parent_process(fd);
	}
	while (wait(0) != -1)
		;
}

int	main(int argc, char *argv[], char *envp[])
{
	/*if (argc > 5)
	{
		ft_putendl_fd("Error: Too many arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}*/
	if (argc < 5)
	{
		ft_putendl_fd("Error: Too few arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	pipex(argv, envp, argc);
	return (0);
}
