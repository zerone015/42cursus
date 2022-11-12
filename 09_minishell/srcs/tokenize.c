/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:13:56 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/12 20:13:31 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../includes/minishell.h"

static int	tokenize_envp(char *input, t_token *token, t_env *env)
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
			add_last(token, WORD, ft_itoa(env->exit_code));
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

static int	tokenize_dquotes(char *input, t_token *token, t_env *env)
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
	return (free_dquotes(word[0]));
}

static int	tokenize_squotes(char *input, t_token *token)
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

static int	tokenize_space(char *input, t_token *token)
{
	int	i;

	i = 0;
	while (ft_isblank(input[i]))
		i++;
	add_last(token, BLANK, ft_strdup(" "));
	return (i);
}

t_token	*tokenize(char *input, t_env *env)
{
	int		i;
	t_token	*token;

	token = init_token();
	i = -1;
	while (input[++i])
	{
		if (!ft_strncmp(input + i, "''", 2) || !ft_strncmp(input + i, "\"\"", 2))
			i++;
		else if (input[i] == '"')
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
