/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:11:51 by yoson             #+#    #+#             */
/*   Updated: 2022/12/21 12:13:32 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	find_heredocs_size(t_token *token)
{
	int		ret;
	t_tnode	*cur;

	ret = 0;
	cur = token->head->next;
	while (cur)
	{
		if (is_heredoc(cur))
			ret++;
		cur = cur->next;
	}
	return (ret);
}

static char	*join_number(char *dest, int src)
{
	char	*str_src;
	char	*ret;

	str_src = ft_itoa(src);
	ret = ft_strjoin(dest, str_src);
	free(str_src);
	return (ret);
}

static void	set_heredocs(t_token *token, t_exec *exec)
{
	int	size;
	int	i;

	size = find_heredocs_size(token);
	exec->heredocs = safe_malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < size)
		(exec->heredocs)[i] = join_number("/tmp/.heredoc", i);
	(exec->heredocs)[i] = NULL;
}

int	heredoc(t_token *token, t_exec *exec)
{
	pid_t	pid;
	int		res;

	set_heredocs(token, exec);
	pid = safe_fork(exec);
	if (pid == 0)
		child_heredoc(token, exec);
	res = parent_heredoc(token, exec);
	return (res);
}
