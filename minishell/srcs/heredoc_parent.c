/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:18:00 by yoson             #+#    #+#             */
/*   Updated: 2022/12/05 13:37:26 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "../includes/minishell.h"

static void	free_limiters(t_tnode *first)
{
	t_tnode	*cur;
	t_tnode	*temp;

	free(first->str);
	cur = first->next;
	while (cur && cur->type == WORD)
	{
		free(cur->str);
		temp = cur;
		cur = cur->next;
		free(temp);
	}
	first->next = cur;
}

static void	change_limiter_to_filename(t_token *token, t_exec *exec)
{
	t_tnode	*cur;
	int		i;

	cur = find_heredoc_limiter(token->head->next);
	i = 0;
	while (cur)
	{
		free_limiters(cur);
		cur->str = ft_strdup((exec->heredocs)[i++]);
		cur = find_heredoc_limiter(cur);
	}
}

int	is_normal_terminated(int status)
{
	if (status && status >> 8 == 0)
		return (FALSE);
	return (TRUE);
}

int	parent_heredoc(t_token *token, t_exec *exec)
{
	int		status;

	wait(&status);
	if (!is_normal_terminated(status))
	{
		exec->env->exit_code = EXIT_FAILURE;
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (-1);
	}
	change_limiter_to_filename(token, exec);
	return (0);
}
