/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/11/12 03:07:26 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../includes/minishell.h"

t_env	*init_envp(char *envp[])
{
	t_env	*env;
	int		i;

	env = init_env();
	while (*envp)
	{
		i = ft_strchr(*envp, '=') - *envp;
		add_enode(env, ft_substr(*envp, 0, i), \
						ft_substr(*envp, i + 1, ft_strlen(*envp)));
		envp++;
	}
	return (env);
}

char	*safe_readline(char *prompt)
{
	char	*input;

	input = readline(prompt);
	free(prompt);
	return (input);
}

void	exit_program(void)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(0);
}

void	child_process(t_token *token, t_env *env, int fd[], int std_fd[])
{
	if (is_builtin(token))
		builtin_process(token, env, fd, std_fd);
	else
		external_process(token, env, fd, std_fd);
}

void	parent_process(t_token *token, int fd[], int std_fd[])
{
	if (last_type(token) == PIPE)
		dup2(fd[0], STDIN_FILENO);
	else
		dup2(std_fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	dup2(std_fd[1], STDOUT_FILENO);
	clear_token(token);
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
	ft_putendl_fd("exit", 1);
	exit(env->exit_code);
	return (0);
}

int	check_exit(t_token *tokens, t_env *env)
{
	char	*first;
	char	**argv;
	int		argc;
	int		fd[2];

	first = tokens->head->next->str;
	if (ft_strncmp(first, "exit", ft_strlen(first)) == 0 && !has_pipe(tokens))
	{
		fd[0] = -1;
		argv = preprocess(tokens, fd);
		argc = 0;
		while (argv[argc])
			argc++;
		shell_exit(argc, argv, env);
		return (1);
	}
	return (0);
}

void	execute_command(char *input, t_env *env, int std_fd[])
{
	t_token	*tokens;
	t_token	*token;
	int		fd[2];
	pid_t	pid;

	safe_signal(SIGINT, SIG_IGN);
	tokens = tokenize(input, env);
	if (check_exit(tokens, env))
		return ;
	while (first_type(tokens) != ERROR)
	{	
		token = parse_token(tokens);
		if (pipe(fd) == -1)
			error(env, NULL, 1);
		pid = fork();
		if (pid == ERROR)
			error(env, NULL, 1);
		else if (pid == 0)
			child_process(token, env, fd, std_fd);
		else if (pid > 0)
			parent_process(token, fd, std_fd);
	}
	env->exit_code = wait_all(pid);
	clear_token(tokens);
	unlink("./.heredoc");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;
	int		is_error;
	int		std_fd[2];

	env = init_envp(envp);
	std_fd[0] = dup(STDIN_FILENO);
	std_fd[1] = dup(STDOUT_FILENO);
	while (argc || argv)
	{
		set_signal(PARENT);
		input = safe_readline(get_prompt(env));
		if (input)
		{
			is_error = syntax_check(&input, env);
			if (*input)
				add_history(input);
			if (!is_error)
				execute_command(input, env, std_fd);
			free(input);
		}
		else
			exit_program();
	}
	return (0);
}
