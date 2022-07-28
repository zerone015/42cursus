/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 03:18:02 by yoson             #+#    #+#             */
/*   Updated: 2022/07/29 05:44:45 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void	child_process(char *argv[], char *envp[], int fd[])
{
	int		infile;
	char	*path;
	char	**cmd;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	cmd = ft_split(argv[2], ' ');
	if (!cmd)
		error();
	path = find_path(argv[2], envp);
	if (!path)
	{
		ft_free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

void	parent_process(char *argv[], char *envp[], int fd[])
{
	int		outfile;
	char	*path;
	char	**cmd;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	cmd = ft_split(argv[3], ' ');
	if (!cmd)
		error();
	path = find_path(argv[3], envp);
	if (!path)
	{
		ft_free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

void	pipex(char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		child_process(argv, envp, fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, fd);
}
