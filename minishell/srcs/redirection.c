/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:14:09 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 17:20:16 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "../includes/minishell.h"

static void	overwrite_output(char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		child_error(NULL, filename, 1);
	dup2(fd, STDOUT_FILENO);
}

static void	append_output(char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 00644);
	if (fd == -1)
		child_error(NULL, filename, 1);
	dup2(fd, STDOUT_FILENO);
}

static void	input(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		if (errno == ENOENT)
			child_error(NULL, filename, 127);
		else
			child_error(NULL, filename, 1);
	}
	dup2(fd, STDIN_FILENO);
}

void	redirection(t_token *token)
{
	char	*redirection;	
	char	*filename;

	redirection = remove_first(token);
	while (first_type(token) == BLANK)
		free(remove_first(token));
	filename = merge_word(token);
	if (ft_strcmp(redirection, ">") == 0)
		overwrite_output(filename);
	else if (ft_strcmp(redirection, ">>") == 0)
		append_output(filename);
	else if (ft_strcmp(redirection, "<") == 0 || \
			ft_strcmp(redirection, "<<") == 0)
		input(filename);
	free(redirection);
	free(filename);
}
