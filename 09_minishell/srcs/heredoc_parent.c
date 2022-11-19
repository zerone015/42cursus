/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:18:00 by yoson             #+#    #+#             */
/*   Updated: 2022/11/19 15:23:13 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	change_limiter_to_filename(t_token *token, t_exec *exec)
{
	t_tnode	*cur;
	int		i;

	cur = find_heredoc_limiter(token->head->next);
	i = 0;
	while (cur)
	{
		free(cur->str);
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
