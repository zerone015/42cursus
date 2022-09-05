/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/09/05 12:46:17 by kijsong          ###   ########.fr       */
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

void	execute_command(char *input, t_env *env)
{
	t_token	*tokens;
	t_token	*token;
	int		fd[2];
	int		oldfd[2];

	safe_signal(SIGINT, SIG_IGN);
	oldfd[0] = dup(STDIN_FILENO);
	oldfd[1] = dup(STDOUT_FILENO);
	tokens = tokenize(input, env);
	while (first_type(tokens) != ERROR)
	{
		token = parse_token(tokens);
		if (pipe(fd) == -1)
		{
			error(env, NULL, 1);
			exit(1);
		}
		if (is_builtin(token))
			builtin_process(token, env, fd, oldfd);
		else
			external_process(token, env, fd, oldfd);
		clear_token(token);
	}
	clear_token(tokens);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;
	int		is_error;

	env = init_envp(envp);
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
				execute_command(input, env);
			free(input);
		}
		else
			exit_program();
	}
	return (0);
}
