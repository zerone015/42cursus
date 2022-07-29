/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 03:18:02 by yoson             #+#    #+#             */
/*   Updated: 2022/07/30 04:44:28 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void	child_process(t_info *info, int *fd, char **envp)
{
	int		infile;
	char	*path;
	char	**cmd;

	infile = open(info->infile, O_RDONLY, 0777);
	if (infile == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	cmd = ft_split(info->cmds[0], ' ');
	if (!cmd)
		error();
	path = find_path(info->paths, cmd[0]);
	if (!path)
		command_not_found(info->cmds[0]);
	if (execve(path, cmd, envp) == -1)
		error();
}

void	parent_process(t_info *info, int *fd, char **envp)
{
	int		outfile;
	char	*path;
	char	**cmd;

	outfile = open(info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	cmd = ft_split(info->cmds[1], ' ');
	if (!cmd)
		error();
	path = find_path(info->paths, cmd[0]);
	if (!path)
		command_not_found(info->cmds[1]);
	if (execve(path, cmd, envp) == -1)
		error();
}

void	pipex(t_info *info, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		child_process(info, fd, envp);
	waitpid(pid, NULL, WNOHANG);
	parent_process(info, fd, envp);
}
