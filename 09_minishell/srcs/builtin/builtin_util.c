/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:09:40 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/05 00:14:37 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include "../../includes/minishell.h"

int	is_pipe(t_token *token)
{
	t_tnode	*node;

	node = token->head->next;
	while (node)
	{
		if (node->type == PIPE)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

int	builtin_error(t_env *env, char *cmd, char *arg, char *err_msg)
{
	if (!err_msg)
		err_msg = strerror(errno);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (arg)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(err_msg, STDERR_FILENO);
	env->exit_code = 1;
	return (ERROR);
}
