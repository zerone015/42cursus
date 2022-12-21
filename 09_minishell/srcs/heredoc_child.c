/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:13:53 by yoson             #+#    #+#             */
/*   Updated: 2022/12/21 19:24:51 by kijsong          ###   ########.fr       */
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
		free(input);
		free(temp);
	}
	free(input);
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

static char	*merge_limiter(t_tnode *cur)
{
	char	*ret;
	char	*temp;

	ret = ft_strdup("");
	while (cur && cur->type == WORD)
	{
		temp = ret;
		ret = ft_strjoin(ret, cur->str);
		free(temp);
		cur = cur->next;
	}
	temp = ret;
	ret = ft_strjoin(ret, "\n");
	free(temp);
	return (ret);
}

static void	make_heredocs(t_token *token, t_exec *exec)
{
	t_tnode	*cur;
	char	*input;
	char	*limiter;

	cur = find_heredoc_limiter(token->head->next);
	while (cur)
	{
		limiter = merge_limiter(cur);
		input = read_input(limiter, exec->env);
		free(limiter);
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
