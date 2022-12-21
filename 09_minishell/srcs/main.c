/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/12/21 17:18:22 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../includes/minishell.h"

static char	*safe_readline(char *prompt)
{
	char	*input;

	input = readline(prompt);
	free(prompt);
	return (input);
}

static void	parse_envp(t_env *env, char *envp[])
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

static void	init_exec(t_exec *exec, char *envp[])
{
	exec->heredocs = NULL;
	exec->has_pipe = FALSE;
	exec->std_fd[READ_FD] = dup(STDIN_FILENO);
	exec->std_fd[WRITE_FD] = dup(STDOUT_FILENO);
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
