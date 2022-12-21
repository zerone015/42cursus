/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:53:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:18:27 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	child_process(t_exec *exec)
{
	if (is_builtin(exec->token))
		child_builtin(exec);
	else
		child_external(exec);
}

static void	parent_process(t_exec *exec)
{
	clear_token(exec->token);
}

static void	execute_with_fork(t_token *tokens, t_exec *exec)
{
	pid_t	pid;
	int		is_sigint;

	while (first_type(tokens) != -1)
	{	
		exec->token = parse_token(tokens);
		pid = safe_fork(exec);
		if (pid == 0)
			child_process(exec);
		else if (pid > 0)
			parent_process(exec);
	}
	is_sigint = FALSE;
	exec->env->exit_code = find_exit_code(wait_all(pid, &is_sigint), is_sigint);
}

int	execute_core(t_token *token, t_exec *exec)
{
	if (!exec->has_pipe && is_builtin(token))
	{
		execute_builtin(make_argv(token), exec->env, FALSE);
		dup2(exec->std_fd[READ_FD], STDIN_FILENO);
		dup2(exec->std_fd[WRITE_FD], STDOUT_FILENO);
	}
	else
		execute_with_fork(token, exec);
	return (exec->env->exit_code);
}
