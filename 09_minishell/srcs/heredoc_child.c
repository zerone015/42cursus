/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:13:53 by yoson             #+#    #+#             */
/*   Updated: 2022/11/23 01:29:31 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/minishell.h"

static char	*read_input(char *limiter, t_env *env)
{
	char	*input;
	char	*join;
	char	*temp;

	echoctl(FALSE);
	join = ft_strdup("");
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		input = get_next_line(STDIN_FILENO);
		if (input == NULL || ft_strcmp(input, limiter) == 0)
			break ;
		if (ft_strchr(input, '$'))
		{
			temp = input;
			input = parse_input(input, env);
			free(temp);
		}
		temp = join;
		join = ft_strjoin(join, input);
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

static void	make_heredocs(t_token *token, t_exec *exec)
{
	t_tnode	*cur;
	char	*input;

	cur = find_heredoc_limiter(token->head->next);
	while (cur)
	{
		input = read_input(ft_strjoin(cur->str, "\n"), exec->env);
		input_to_file(input, *(exec->heredocs)++);
		free(input);
		cur = find_heredoc_limiter(cur);
	}
}

void	child_heredoc(t_token *token, t_exec *exec)
{
	set_signal(CHILD);
	make_heredocs(token, exec);
	exit(EXIT_SUCCESS);
}
