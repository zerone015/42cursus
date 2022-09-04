/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:14:09 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/05 00:01:02 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../includes/minishell.h"

void	overwrite_output(char *filename, int *flag)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		child_error(NULL, filename, 1);
	dup2(fd, STDOUT_FILENO);
	*flag = 1;
}

void	append_output(char *filename, int *flag)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 00644);
	if (fd == -1)
		child_error(NULL, filename, 1);
	dup2(fd, STDOUT_FILENO);
	*flag = 1;
}

void	overwrite_input(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		child_error("No such file or directory", filename, 127);
	dup2(fd, STDIN_FILENO);
}

void	append_input(char *limiter)
{
	char	*line;
	int		fd;

	echoctl(FALSE);
	fd = open("./.heredoc", O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		child_error(NULL, ".heredoc", 1);
	while (1)
	{
		ft_putstr_fd("> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	fd = open("./.heredoc", O_RDONLY);
	dup2(fd, STDIN_FILENO);
}

void	redirection(t_token *token, int *flag)
{
	char	*redirection;	
	char	*filename;

	redirection = remove_first(token);
	while (first_type(token) == BLANK)
		free(remove_first(token));
	filename = merge_word(token);
	if (ft_strcmp(redirection, ">") == 0)
		overwrite_output(filename, flag);
	else if (ft_strcmp(redirection, ">>") == 0)
		append_output(filename, flag);
	else if (ft_strcmp(redirection, "<") == 0)
		overwrite_input(filename);
	else if (ft_strcmp(redirection, "<<") == 0)
		append_input(filename);
	free(redirection);
	free(filename);
}
