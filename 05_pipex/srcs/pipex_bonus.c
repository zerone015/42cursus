/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 03:18:02 by yoson             #+#    #+#             */
/*   Updated: 2022/11/01 01:35:50 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int	is_heredoc(char *arg)
{
	if (ft_strncmp(arg, "here_doc", ft_strlen(arg)) == 0)
		return (TRUE);
	return (FALSE);
}

static void	child_process(char *arg, char *envp[], int fd[], char *paths[])
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(arg, envp, paths);
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

static void	parent_process(int fd[])
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}

void	here_doc(char *limiter)
{
	int		fd;
	char	*line;

	fd = open("./.here_doc", O_WRONLY | O_CREAT | O_TRUNC, 00644);
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
	fd = open("./.here_doc", O_RDONLY);
	if (fd == -1)
		ft_perror("here_doc", EXIT_FAILURE);
	dup2(fd, STDIN_FILENO);
}

int	redirection_stdin(char *argv[])
{
	char	*limiter;
	int		fd;
	int		ret;

	if (is_heredoc(argv[1]))
	{
		limiter = ft_strjoin(argv[2], "\n");
		if (!limiter)
			ft_perror(NULL, EXIT_FAILURE);
		here_doc(limiter);
		free(limiter);
		ret = 2;
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_perror(argv[1], EXIT_FAILURE);
		ret = 1;
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (ret);
}

void	pipex(int argc, char *argv[], char *envp[], char *paths[])
{
	pid_t	pid;
	int		fd[2];
	int		i;

	i = redirection_stdin(argv);
	while (++i < argc - 2)
	{
		if (pipe(fd) == -1)
			ft_strerror();
		pid = fork();
		if (pid == -1)
			ft_strerror();
		else if (pid == 0)
			child_process(argv[i], envp, fd, paths);
		parent_process(fd);
	}
	last_child_process(argv, argc, envp, paths);
	close(fd[0]);
	close(fd[1]);
	while (wait(NULL) != -1)
		;
}

static char	**parse_paths(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
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
