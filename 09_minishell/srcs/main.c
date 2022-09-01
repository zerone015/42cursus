/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/09/01 22:27:44 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> //getcwd
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

int	g_exit_code;

void	update_pwd(t_env *env)
{
	t_enode	*pwd;

	pwd = find_key(env, "PWD"); //유저가 unset 가능한지 확인
	free(pwd->val);
	pwd->val = getcwd(NULL, 0);
	if (!pwd->val)
		ft_perror(NULL);
}

char	*get_prompt(t_env *env)
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

int	tokenize_envp(char *input, t_token *token, t_env *env)
{
	int		i;
	char	*key;
	t_enode	*node;

	i = 0;
	if (!ft_isalpha(input[i]) && input[i] != '_')
	{
		if (!ft_isdigit(input[i]) && input[i] != '?')
		{
			add_last(token, WORD, ft_strdup("$"));
			return (0);
		}
		if (input[i] == '?')
			add_last(token, WORD, ft_itoa(g_exit_code));
		return (1);
	}
	while (ft_isalpha(input[i]) || ft_isdigit(input[i]) || input[i] == '_')
		i++;
	key = ft_substr(input, 0, i);
	node = find_key(env, key);
	if (node)
		add_last(token, WORD, ft_strdup(node->val));
	free(key);
	return (i);
}

int	tokenize_dquotes(char *input, t_token *token, t_env *env)
{
	char	*word[2];
	char	*envp;
	int		start;

	if (!ft_strchr(input + 1, '"'))
	{
		add_last(token, WORD, ft_strdup("\""));
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
			add_last(token, WORD, word[1]);
			start += ft_strlen(word[1]);
		}
		start += tokenize_envp(envp + 1, token, env) + 1;
		envp = ft_strchr(&word[0][start], '$');
	}
	add_last(token, WORD, ft_substr(word[0], start, ft_strlen(word[0])));
	return (ft_strlen(word[0]) + 1);
}

int	tokenize_squotes(char *input, t_token *token)
{
	char	*word;

 	if (!ft_strchr(input + 1, '\''))
	{
		add_last(token, WORD, ft_strdup("'"));
		return (0);
	}
	word = ft_substr(input, 0, ft_strchr(input, '\'') - input);
	add_last(token, WORD, word);
	return (ft_strlen(word) + 1);
}

int	tokenize_space(char *input, t_token *token)
{
	int	i;

	i = 0;
	while (ft_isblank(input[i]))
		i++;
	add_last(token, BLANK, ft_strdup(" "));
	return (i);
}

int	tokenize_redirect(char *input, t_token *token)
{
	int	i;

	i = ft_isredirect(input);
	i *= (i > 0) - (i < 0);
	add_last(token, REDIRECT, ft_substr(input, 0, i));
	return (i - 1);
}

int	is_normal(char c)
{
	if (c == '|' || c == '"' || c == '\'' || c == '$')
		return (FALSE);
	if (ft_isblank(c) || c == '>' || c == '<')
		return (FALSE);
	return (TRUE);
}

int	tokenize_normal(char *input, t_token *token)
{
	int	i;

	i = 0;
	while (input[i] && is_normal(input[i]))
		i++;
	add_last(token, WORD, ft_substr(input, 0, i));
	return (i - 1);
}

t_token	*tokenize(char *input, t_env *env)
{
	int		i;
	t_token	*token;

	token = init_token();
	i = -1;
	while (input[++i])
	{
		if (input[i] == '"')
			i += tokenize_dquotes(input + i + 1, token, env);
		else if (input[i] == '\'')
			i += tokenize_squotes(input + i + 1, token);
		else if (ft_isblank(input[i]))
			i += tokenize_space(input + i + 1, token);
		else if (ft_isredirect(input + i))
			i += tokenize_redirect(input + i, token);
		else if (input[i] == '$')
			i += tokenize_envp(input + i + 1, token, env);
		else if (input[i] == '|')
			add_last(token, PIPE, ft_strdup("|"));
		else
			i += tokenize_normal(input + i, token);
	}
	return (token);
}

int	is_builtin(t_token *token)
{
	t_tnode		*node;
	char		*cmd;
	char		*temp;
	const char	*builtin = "cd\0echo\0env\0exit\0export\0pwd\0unset";

	node = token->head;
	cmd = ft_strdup("");
	while (node->type == WORD)
	{
		temp = cmd;
		cmd = ft_strjoin(temp, node->str);
		free(temp);
		node = node->next;
	}
	temp = ft_strnstr(builtin, cmd, 34);
	free(cmd);
	if (!temp)
		return (FALSE);
	return (TRUE);
}

t_token	*merge_token(t_token *tokens)
{
	t_token	*token;
	int		type;

	token = init_token();
	if (get_first_type(tokens) == PIPE)
		add_last(token, PIPE, remove_first(tokens));
	if (get_first_type(tokens) == BLANK)
		remove_first(tokens);
	type = get_first_type(tokens);
	while (type != PIPE && type != ERROR)
	{
		add_last(token, type, remove_first(tokens));
		type = get_first_type(tokens);
	}
	redirect_to_last(token);
	if (type == PIPE)
		add_last(token, PIPE, ft_strdup("|"));
	return (token);
}

int	is_first_pipe(t_token *tokens)
{
	t_tnode	*node;

	node = tokens->head->next;
	if (!node)
		return (TRUE);
	if (node->type == BLANK)
		node = node->next;
	if (node && node->type == PIPE)
		return (FALSE);
	return (TRUE);
}

int	syntax_error(t_token *token, char *err_msg)
{
	t_tnode	*node;
	t_tnode	*temp;

	if (*err_msg != '\0')
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putendl_fd(err_msg, 2);
	}
	node = token->head;
	while (node)
	{
		temp = node->next;
		free(node->str);
		free(node);
		node = temp;
	}
	free(token);
	return (ERROR);
}

int	syntax_check(t_token *token)
{
	if (!token->head->next)
		return (syntax_error(token, ""));
	return (0);
}

void	execute_command(char *input, t_env *env)
{
	t_token	*tokens;
	t_token	*token;

	tokens = tokenize(input, env);
	if (!is_first_pipe(tokens))
	{
		syntax_error(tokens, "syntax error near unexpected token '|'");
		return ;
	}
	while (get_first_type(tokens) != ERROR)
	{
		token = merge_token(tokens);
		if (syntax_check(token) == ERROR)
			return ;
		while (get_first_type(token) != ERROR)
			ft_putstr_fd(remove_first(token), 1);
		ft_putchar_fd('\n', 1);
		// if (is_builtin(token))
		// 	builtin_process(token, env);
		// else
		// 	external_process(token, env);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;

	env = init_envp(envp);
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
