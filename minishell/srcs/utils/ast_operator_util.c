/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_operator_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:08:56 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:24:04 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ast_pipe_left(t_anode *ast, t_exec *exec, int pipe_fd[])
{
	if (safe_fork(exec) == 0)
	{
		close(pipe_fd[READ_FD]);
		dup2(pipe_fd[WRITE_FD], STDOUT_FILENO);
		ast_preorder(ast->left, exec);
		exit(EXIT_SUCCESS);
	}
	close(pipe_fd[WRITE_FD]);
}

static pid_t	ast_pipe_right(t_anode *ast, t_exec *exec, int pipe_fd[])
{
	pid_t	pid;

	pid = safe_fork(exec);
	if (pid == 0)
	{
		close(pipe_fd[WRITE_FD]);
		dup2(pipe_fd[READ_FD], STDIN_FILENO);
		exit(ast_preorder(ast->right, exec));
	}
	close(pipe_fd[READ_FD]);
	return (pid);
}

int	ast_pipe(t_anode *ast, t_exec *exec)
{
	int		pipe_fd[2];
	int		is_sigint;
	int		exit_code;
	pid_t	right_pid;

	exec->has_pipe = TRUE;
	safe_pipe(pipe_fd, exec);
	ast_pipe_left(ast, exec, pipe_fd);
	right_pid = ast_pipe_right(ast, exec, pipe_fd);
	is_sigint = FALSE;
	exit_code = find_exit_code(wait_all(right_pid, &is_sigint), is_sigint);
	exec->has_pipe = FALSE;
	return (exit_code);
}

int	ast_logical_and(t_anode *ast, t_exec *exec)
{
	int	ret;

	ret = ast_preorder(ast->left, exec);
	if (ret == 0)
		ret = ast_preorder(ast->right, exec);
	return (ret);
}

int	ast_logical_or(t_anode *ast, t_exec *exec)
{
	int	ret;

	ret = ast_preorder(ast->left, exec);
	if (ret != 0)
		ret = ast_preorder(ast->right, exec);
	return (ret);
}
