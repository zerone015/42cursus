/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/11/14 21:33:11 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../includes/minishell.h"

char	*safe_readline(char *prompt)
{
	char	*input;

	input = readline(prompt);
	free(prompt);
	return (input);
}

void	child_builtin(t_exec *exec)
{
	char	**argv;
	int		out_redirection;
	
	dup2(exec->std_fd[0], STDIN_FILENO);
	close(exec->pipe_fd[0]);
	if (first_type(exec->token) == PIPE)
		free(remove_first(exec->token));
	out_redirection = 0;
	argv = make_argv(exec->token, &out_redirection);
	if (!out_redirection && first_type(exec->token) == PIPE)
		dup2(exec->pipe_fd[1], STDOUT_FILENO);
	close(exec->pipe_fd[1]);
	execute_builtin(argv, exec->env, TRUE);
}

int	is_builtin(t_token *token)
{
	t_tnode		*node;
	char		*cmd;
	char		*temp;
	const char	*builtin = "\0cd\0echo\0env\0exit\0export\0pwd\0unset";

	node = token->head->next;
	cmd = ft_strdup("");
	while (node && node->type == PIPE)
		node = node->next;
	while (node && node->type == WORD)
	{
		temp = cmd;
		cmd = ft_strjoin(cmd, node->str);
		free(temp);
		node = node->next;
	}
	temp = strnstr_strict(builtin, cmd, 35);
	free(cmd);
	if (!temp)
		return (FALSE);
	return (TRUE);
}

void	child_process(t_exec *exec)
{
	if (is_builtin(exec->token))
		child_builtin(exec);
	else
		child_external(exec);
}

void	parent_process(t_exec *exec)
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

int	wait_all(pid_t last_pid)
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = 1;
	while (pid != -1)
	{
		pid = wait(&status);
		if (pid == last_pid)
			ret = status >> 8;
	}
	return (ret);
}

int	exit_program(t_token *tokens, t_env *env)
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

int	is_exit(t_token *tokens)
{
	char	*first;

	first = tokens->head->next->str;
	if (ft_strncmp(first, "exit", 5) == 0)
		return (TRUE);
	return (FALSE);
}

t_token	*parse_token(t_token *tokens)
{
	t_token	*token;
	int		type;

	token = init_token();
	if (first_type(tokens) == PIPE)
		add_last(token, PIPE, remove_first(tokens));
	if (first_type(tokens) == BLANK)
		free(remove_first(tokens));
	type = first_type(tokens);
	while (type != PIPE && type != -1)
	{
		add_last(token, type, remove_first(tokens));
		type = first_type(tokens);
	}
	redirect_to_last(token);
	if (type == PIPE)
		add_last(token, PIPE, ft_strdup("|"));
	return (token);
}

void	execute_with_fork(t_token *tokens, t_exec *exec)
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

	safe_signal(SIGINT, SIG_IGN);
	tokens = tokenize(input, exec->env);
	if (is_exit(tokens) && !has_pipe(tokens))
		exit_program(tokens, exec->env);
	else if (is_builtin(tokens) && !has_pipe(tokens))
		execute_builtin(make_argv(tokens, NULL), exec->env, FALSE);
	else
		execute_with_fork(tokens, exec);
	clear_token(tokens);
	unlink("/tmp/.heredoc");
}

void	parse_envp(t_env *env, char *envp[])
{
	int		i;

	while (*envp)
	{
		i = ft_strchr(*envp, '=') - *envp;
		add_enode(env, ft_substr(*envp, 0, i), \
						ft_substr(*envp, i + 1, ft_strlen(*envp)));
		envp++;
	}
}

void	init_exec(t_exec *exec, char *envp[])
{
	exec->std_fd[0] = dup(STDIN_FILENO);
	exec->std_fd[1] = dup(STDOUT_FILENO);
	exec->pipe_fd[0] = -1;
	exec->pipe_fd[1] = -1;
	exec->env = init_env();
	parse_envp(exec->env, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_exec	exec;
	char	*input;
	int		is_error;

	init_exec(&exec, envp);
	while (argc || argv)
	{
		set_signal(PARENT);
		input = safe_readline(get_prompt(exec.env));
		if (input)
		{
			is_error = check_syntax(&input, exec.env);
			if (*input)
				add_history(input);
			if (!is_error)
				execute_command(input, &exec);
			free(input);
		}
		else
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
