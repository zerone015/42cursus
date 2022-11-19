/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:18:57 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/19 14:58:00 by yoson            ###   ########.fr       */
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
		dup2(exec->pipe_fd[0], STDIN_FILENO);
	else
		dup2(exec->std_fd[0], STDIN_FILENO);
	close(exec->pipe_fd[0]);
	close(exec->pipe_fd[1]);
	dup2(exec->std_fd[1], STDOUT_FILENO);
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
	exec->env->exit_code = wait_all(pid);
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
			execute_builtin(make_argv(tokens, NULL), exec->env, FALSE);
		else
			execute_with_fork(tokens, exec);
	}
	clear_token(tokens);
	clear_heredocs(exec);
}
