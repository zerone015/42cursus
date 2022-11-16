/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:20:13 by yoson             #+#    #+#             */
/*   Updated: 2022/11/16 18:41:14 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clear_heredocs(t_exec *exec)
{
	int	i;

	i = 0;
	if (!exec->heredocs)
		return ;
	while (exec->heredocs[i])
	{
		unlink(exec->heredocs[i]);
		free(exec->heredocs[i++]);
	}
	free(exec->heredocs);
	exec->heredocs = NULL;
}

t_tnode	*skip_blank(t_tnode *node)
{
	while (node->type == BLANK)
		node = node->next;
	return (node);
}

t_tnode	*find_heredoc_limiter(t_tnode *node)
{
	while (node)
	{
		if (is_heredoc(node))
			return (skip_blank(node->next));
		node = node->next;
	}
	return (NULL);
}

int	is_heredoc(t_tnode *node)
{
	if (node->type == REDIRECT && ft_strcmp(node->str, "<<") == 0)
		return (TRUE);
	return (FALSE);
}

int	has_heredoc(t_token *token)
{
	t_tnode	*node;

	node = token->head->next;
	while (node)
	{
		if (is_heredoc(node))
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}
