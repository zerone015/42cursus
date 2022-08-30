/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/08/30 16:55:56 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

void	update_pwd(t_list *env)
{
	t_node	*pwd;

	pwd = find_key(env, "PWD"); //unset 가능한지 확인
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
	// home = ft_strjoin("/Users/", find_key(env, "USER")->value);
	if (!ft_strcmp(pwd, home))
		pwd = "~";
	else if (ft_strlen(pwd) == 1)
		pwd = "/";
	else
		pwd = ft_strrchr(pwd, '/') + 1;
	return (ft_strjoin(pwd, " $ "));
}

static t_list	*init_env(char *envp[])
{
	t_list	*env;
	size_t	i;

	env = init_list();
	while (*envp)
	{
 		i = ft_strchr(*envp, '=') - *envp;
		add_last(env, ft_substr(*envp, 0, i), ft_substr(*envp, i + 1, ft_strlen(*envp)));
		envp++;
	}
	return (env);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*env;
	char	*input;

	(void)argc;
	(void)argv;
	env = init_env(envp);
	// signal();
	while (42)
	{
		input = readline(get_prompt(env));
		if (input)
		{
			add_history(input);
			// parse_input(input);
			free(input);
		}
	}
	return (0);
}
