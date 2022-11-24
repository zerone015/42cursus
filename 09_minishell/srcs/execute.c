/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:18:57 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/24 14:16:28 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
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
	if (last_type(exec->token) == PIPE)
		dup2(exec->pipe_fd[READ_FD], STDIN_FILENO);
	else
		dup2(exec->std_fd[READ_FD], STDIN_FILENO);
	close(exec->pipe_fd[READ_FD]);
	close(exec->pipe_fd[WRITE_FD]);
	dup2(exec->std_fd[WRITE_FD], STDOUT_FILENO);
	clear_token(exec->token);
}

static int	exit_minishell(t_token *tokens, t_env *env)
{
	int		argc;
	char	**argv;

	argc = find_argv_size(tokens);
	argv = make_argv(tokens, NULL);
	unlink("/tmp/.heredoc");
	if (argc >= 2 && !is_number(argv[1]))
	{
		builtin_error(env, "exit", argv[1], "numeric argument required");
		exit(255);
	}
	if (argc > 2)
	{
		ft_free(argv);
		return (builtin_error(env, "exit", NULL, "too many arguments"));
	}
	env->exit_code = 0;
	if (argc == 2)
	{
		if (is_number(argv[1]))
			env->exit_code = ft_atoi(argv[1]) & 255;
	}
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(env->exit_code);
	return (0);
}

static void	execute_with_fork(t_token *tokens, t_exec *exec)
{
	pid_t	pid;
	int		is_sigint;

	while (first_type(tokens) != -1)
	{	
		exec->token = parse_token(tokens);
		if (pipe(exec->pipe_fd) == -1)
		{
			error(exec->env, NULL, 1);
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
			error(exec->env, NULL, 1);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			child_process(exec);
		else if (pid > 0)
			parent_process(exec);
	}
	is_sigint = FALSE;
	exec->env->exit_code = find_exit_code(wait_all(pid, &is_sigint), is_sigint);
}

void	execute_command(char *input, t_exec *exec)
{
	t_token	*tokens;
	int		heredoc_res;

	heredoc_res = 0;
	safe_signal(SIGINT, SIG_IGN);
	tokens = tokenize(input, exec->env);
	if (has_heredoc(tokens))
		heredoc_res = heredoc(tokens, exec);
	if (heredoc_res == 0)
	{
		if (is_exit(tokens->head->next) && !has_pipe(tokens))
			exit_minishell(tokens, exec->env);
		else if (is_builtin(tokens) && !has_pipe(tokens))
		{
			execute_builtin(make_argv(tokens, NULL), exec->env, FALSE);
			dup2(exec->std_fd[READ_FD], STDIN_FILENO);
			dup2(exec->std_fd[WRITE_FD], STDOUT_FILENO);
		}
		else
			execute_with_fork(tokens, exec);
	}
	clear_token(tokens);
	clear_heredocs(exec);
}
