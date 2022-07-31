/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 03:18:02 by yoson             #+#    #+#             */
/*   Updated: 2022/08/01 06:18:11 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void	child_process(char *argv[], char *envp[], int fd[])
{
	int		infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error(argv[1], strerror(errno), EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char *argv[], char *envp[], int fd[])
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (outfile == -1)
		error(argv[4], strerror(errno), EXIT_FAILURE);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

void	pipex(char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error(0, 0, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		error(0, 0, EXIT_FAILURE);
	if (pid == 0)
		child_process(argv, envp, fd);
	waitpid(pid, NULL, WNOHANG);
	parent_process(argv, envp, fd);
}
