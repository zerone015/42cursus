/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:29:07 by son-yeong-w       #+#    #+#             */
/*   Updated: 2022/11/24 12:31:34 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char *find_env_next_address(char *str)
{
	if (*str == '$')
	{
		str++;
		if (*str == '?')
			str++;
	}
	while (*str)
	{
		if (*str != '_' && !ft_isalnum(*str))
			return (str);
		str++;
	}
	return (str);
}

static char	*replace_env(char *str, t_env *env)
{
	char	*ret;
	char	*key;
	t_enode	*node;

	if (str[1] == '?')
		ret = ft_itoa(env->exit_code);
	else if (ft_isdigit(str[1]))
		ret = ft_strdup("");
	else if (!ft_isalpha(str[1]) && str[1] != '_')
		ret = ft_substr(str, 0, find_env_next_address(str) - str);
	else
	{
		key = ft_substr(str, 1, find_env_next_address(str) - str - 1);
		node = find_key(env, key);
		if (node)
			ret = ft_strdup(node->val);
		else
			ret = ft_strdup("");
		free(key);
	}
	return (ret);
}

static char	*parse_join(char *input, char *join, t_env *env)
{
	char	*word;
	char	*env_value;
	char	*temp;

	word = ft_substr(input, 0, ft_strchr(input, '$') - input);
	join = ft_strjoin(join, word);
	free(word);
	temp = join;
	env_value = replace_env(ft_strchr(input, '$'), env);
	join = ft_strjoin(join, env_value);
	free(temp);
	free(env_value);
	return (join);
}

char	*parse_input(char *input, t_env *env)
{
	char	*temp;
	char	*join;

	join = ft_strdup("");
	while (*input)
	{
		temp = join;
		if (ft_strchr(input, '$'))
		{
			join = parse_join(input, join, env);
			input = find_env_next_address(ft_strchr(input, '$'));
		}
		else
		{
			join = ft_strjoin(join, input);
			*input = '\0';
		}
		free(temp);
	}
	return (join);
}
