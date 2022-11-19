/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:13:53 by yoson             #+#    #+#             */
/*   Updated: 2022/11/19 14:59:12 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/minishell.h"

static char	*read_input(char *limiter)
{
	char	*line;
	char	*join;
	char	*temp;

	echoctl(FALSE);
	join = ft_strdup("");
	while (1)
	{
		ft_putstr_fd("> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || ft_strcmp(line, limiter) == 0)
			break ;
		temp = join;
		join = ft_strjoin(join, line);
		free(temp);
	}
	return (join);
}

static void	input_to_file(char *input, char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		child_error(NULL, "heredoc", 1);
	write(fd, input, ft_strlen(input));
	close(fd);
}

static void	make_heredocs(t_token *token, char **heredocs)
{
	t_tnode	*cur;
	char	*input;

	cur = find_heredoc_limiter(token->head->next);
	while (cur)
	{
		input = read_input(ft_strjoin(cur->str, "\n"));
		input_to_file(input, *heredocs++);
		free(input);
		cur = find_heredoc_limiter(cur);
	}
}

void	child_heredoc(t_token *token, char **heredocs)
{
	set_signal(CHILD);
	make_heredocs(token, heredocs);
	exit(EXIT_SUCCESS);
}
