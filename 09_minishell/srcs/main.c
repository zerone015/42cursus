/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/08/31 22:42:15 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> //getcwd
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

int	g_exit_code;

void	update_pwd(t_list *env)
{
	t_lnode	*pwd;

	pwd = find_key(env, "PWD"); //유저가 unset 가능한지 확인
	free(pwd->val);
	pwd->val = getcwd(NULL, 0);
	if (!pwd->val)
		ft_perror(NULL);
}

char	*get_prompt(t_list *env)
{
	char	*pwd;
	char	*home;

	update_pwd(env);
	pwd = find_key(env, "PWD")->val;
	home = find_key(env, "HOME")->val;
	// if (ft_strcmp(pwd, home) == 0)
	// 	pwd = "~";
	if (ft_strlen(pwd) == 1)
		pwd = "/";
	else
		pwd = ft_strrchr(pwd, '/') + 1;
	return (ft_strjoin(pwd, " $ "));
}

t_list	*init_lnode(char *envp[])
{
	t_list	*env;
	int		i;

	env = init_list();
	while (*envp)
	{
		i = ft_strchr(*envp, '=') - *envp;
		add_last(env, ft_substr(*envp, 0, i), \
						ft_substr(*envp, i + 1, ft_strlen(*envp)));
		envp++;
	}
	return (env);
}

int	ft_isredirect(char *input)
{
	if (ft_strncmp(input, "<<", 2) == 0)
		return (2);
	else if (ft_strncmp(input, ">>", 2) == 0)
		return (-2);
	else if (*input == '<')
		return (1);
	else if (*input == '>')
		return (-1);
	return (0);
}

int	tokenize_envp(char *input, t_queue *token, t_list *env)
{
	int		i;
	char	*key;
	t_lnode	*node;

	i = 0;
	if (!ft_isalpha(input[i]) && input[i] != '_')
	{
		if (!ft_isdigit(input[i]) && input[i] != '?')
		{
			enqueue(token, WORD, ft_strdup("$"));
			return (0);
		}
		if (input[i] == '?')
			enqueue(token, WORD, ft_itoa(g_exit_code));
		return (1);
	}
	while (ft_isalpha(input[i]) || ft_isdigit(input[i]) || input[i] == '_')
		i++;
	key = ft_substr(input, 0, i);
	node = find_key(env, key);
	if (node)
		enqueue(token, WORD, ft_strdup(node->val));
	free(key);
	return (i);
}

int	tokenize_dquotes(char *input, t_queue *token, t_list *env)
{
	char	*word[2];
	char	*envp;
	int		start;

	if (!ft_strchr(input + 1, '"'))
	{
		enqueue(token, WORD, ft_strdup("\""));
		return (0);
	}
	word[0] = ft_substr(input, 0, ft_strchr(input, '"') - input);
	start = 0;
	envp = ft_strchr(&word[0][start], '$');
	while (envp)
	{
		if (envp - word[0] - start > 0)
		{
			word[1] = ft_substr(word[0], start, envp - word[0] - start);
			enqueue(token, WORD, word[1]);
			start += ft_strlen(word[1]);
		}
		start += tokenize_envp(envp + 1, token, env) + 1;
		envp = ft_strchr(&word[0][start], '$');
	}
	enqueue(token, WORD, ft_substr(word[0], start, ft_strlen(word[0])));
	return (ft_strlen(word[0]) + 1);
}

int	tokenize_squotes(char *input, t_queue *token)
{
	char	*word;

 	if (!ft_strchr(input + 1, '\''))
	{
		enqueue(token, WORD, ft_strdup("'"));
		return (0);
	}
	word = ft_substr(input, 0, ft_strchr(input, '\'') - input);
	enqueue(token, WORD, word);
	return (ft_strlen(word) + 1);
}

int	tokenize_space(char *input, t_queue *token)
{
	int	i;

	i = 0;
	while (ft_isblank(input[i]))
		i++;
	enqueue(token, BLANK, ft_strdup(" "));
	return (i);
}

int	tokenize_redirect(char *input, t_queue *token)
{
	int	i;

	i = ft_isredirect(input);
	i *= (i > 0) - (i < 0);
	enqueue(token, REDIRECT, ft_substr(input, 0, i));
	return (i - 1);
}

int	is_normal(char c)
{
	if (c == '|' || c == '"' || c == '\'' || c == '$' || ft_isblank(c) || c == '>' || c == '<')
		return (FALSE);
	return (TRUE);
}

int	tokenize_normal(char *input, t_queue *token)
{
	int	i;

	i = 0;
	while (input[i] && is_normal(input[i]))
		i++;
	enqueue(token, WORD, ft_substr(input, 0, i));
	return (i - 1);
}

t_queue	*tokenize(char *input, t_list *env)
{
	int		i;
	t_queue	*token;

	token = init_queue();
	i = -1;
	while (input[++i])
	{
		if (input[i] == '"')
			i += tokenize_dquotes(input + i + 1, token, env);
		else if (input[i] == '\'')
			i += tokenize_squotes(input + i + 1, token);
		else if (ft_isblank(input[i]))
			i += tokenize_space(input + i + 1, token);
		else if (ft_isredirect(input))
			i += tokenize_redirect(input + i, token);
		else if (input[i] == '$')
			i += tokenize_envp(input + i + 1, token, env);
		else if (input[i] == '|')
			enqueue(token, PIPE, ft_strdup("|"));
		else
			i += tokenize_normal(input + i, token);
	}
	return (token);
}

void	execute_command(char *input, t_list *env)
{
	t_queue	*token;
	char	*str;

	token = tokenize(input, env);
	str = dequeue(token);
	while (str)
	{
		printf("%s \n", str);
		str = dequeue(token);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*env;
	char	*input;

	env = init_lnode(envp);
	// receive_signal();
	while (argc || argv)
	{
		input = readline(get_prompt(env));
		if (input)
		{
			add_history(input);
			execute_command(input, env);
			free(input);
		}
	}
	return (0);
}
