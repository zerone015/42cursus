/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/08/30 21:50:49 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

void	update_pwd(t_list *env)
{
	t_node	*pwd;

	pwd = find_key(env, "PWD"); //유저가 unset 가능한지 확인
	free(pwd->val);
	pwd->val = getcwd(NULL, 0);
	if (!pwd->val)
	{
		printf("%s \n", strerror(errno));
		exit(1);
	}
}

char	*get_prompt(t_list *env)
{
	char	*pwd;
	char	*home;

	update_pwd(env);
	pwd = find_key(env, "PWD")->val;
	home = find_key(env, "HOME")->val;
	if (!ft_strcmp(pwd, home))
		pwd = "~";
	else if (ft_strlen(pwd) == 1)
		pwd = "/";
	else
		pwd = ft_strrchr(pwd, '/') + 1;
	return (ft_strjoin(pwd, " $ "));
}

t_list	*init_env(char *envp[])
{
	t_list	*env;

	env = init_list();
	while (*envp)
	{
 		i = ft_strchr(*envp, '=') - *envp;
		add_last(env, ft_substr(*envp, 0, i), ft_substr(*envp, i + 1, ft_strlen(*envp)));
		envp++;
	}
	return (env);
}

enum e_type
{
	NUL,
	WORD,
	PIPE,
	REDIRECT,
	S_QUOTES,
	D_QUOTES
};

char	**analyze_syntax(char *input)
{

}

void	tokenize(char *input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\"')
		{
			while (input[i] && input[i] != '\"')
			{
				if (input[i] == '$')
				
				i++;
			}
		}
		else if (input[i] == '\'')
		{
			while (input[i] && input[i] != '\'')
				i++;
		}
		i++;
	}
}

void	execute_command(char *input, t_list *env)
{
	char	**cmd;

	cmd = analyze_syntax(input);
	execute(cmd, env);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*env;
	char	*input;

	env = init_env(envp);
	receive_signal();
	while (argc || argv)
	{
		input = readline(get_prompt(env));
		if (input)
		{
			add_history(input);
			execute_command(input);
			free(input);
		}
	}
	return (0);
}
