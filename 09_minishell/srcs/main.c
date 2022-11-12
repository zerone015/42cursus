/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/11/12 18:51:10 by yoson            ###   ########.fr       */
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

void	exit_program(int exit_code)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(exit_code);
}


void	child_builtin(t_exec *exec)
{
	if (first_type(exec->token) == PIPE)
		free(remove_first(exec->token));
	dup2(exec->std_fd[0], STDIN_FILENO);
	execute_builtin(preprocess(exec->token, exec->pipe_fd), exec->env, TRUE);
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

int	shell_exit(int argc, char *argv[], t_env *env)
{
	if (argc >= 2 && !is_number(argv[1]))
	{
		builtin_error(env, "exit", argv[1], "numeric argument required");
		exit(255);
	}
	if (argc > 2)
		return (builtin_error(env, "exit", NULL, "too many arguments"));
	env->exit_code = 0;
	if (argc == 2)
	{
		if (is_number(argv[1]))
			env->exit_code = ft_atoi(argv[1]) & 255;
	}
	exit_program(env->exit_code);
	return (0);
}

int	execute_exit(t_token *tokens, t_exec *exec)
{
	char	*first;
	char	**argv;
	int		argc;

	first = tokens->head->next->str;
	if (ft_strncmp(first, "exit", 5) == 0 && !has_pipe(tokens))
	{
		argv = preprocess(tokens, exec->pipe_fd);
		argc = 0;
		while (argv[argc])
			argc++;
		shell_exit(argc, argv, exec->env);
		clear_token(tokens);
		unlink("./.heredoc");
		return (0);
	}
	return (-1);
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
	if (execute_exit(tokens, exec) == 0)
		return ;
	if (is_builtin(tokens) && !has_pipe(tokens))
		execute_builtin(preprocess(tokens, exec->pipe_fd), exec->env, FALSE);
	else
		execute_with_fork(tokens, exec);
	clear_token(tokens);
	unlink("./.heredoc");
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
			is_error = syntax_check(&input, exec.env);
			if (*input)
				add_history(input);
			if (!is_error)
				execute_command(input, &exec);
			free(input);
		}
		else
			exit_program(EXIT_SUCCESS);
	}
	return (0);
}
