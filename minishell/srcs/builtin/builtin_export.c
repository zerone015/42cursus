/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:47:58 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:23:57 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/env.h"
#include "../../includes/minishell.h"

char	*get_key(char *str, int size)
{
	char	*key;
	int		i;

	i = size;
	while (i--)
	{
		if (!ft_isdigit(*str) && !ft_isalpha(*str) && *str != '_')
			size--;
		str++;
	}
	key = safe_malloc(size + 1);
	key[size] = '\0';
	while (size)
	{
		str--;
		if (ft_isdigit(*str) || ft_isalpha(*str) || *str == '_')
			key[--size] = *str;
	}
	return (key);
}

void	update_export(char *key, char *val, t_env *env)
{
	t_enode	*node;

	node = find_key(env, key);
	if (node)
	{
		free(key);
		if (is_essential(node->key))
			return ;
		if (node->val)
			free(node->val);
		node->val = val;
	}
	else
		add_enode(env, key, val);
}

void	add_export(char *str, t_env *env)
{
	char	*equal;
	char	*key;
	char	*val;
	int		size;

	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		ft_putstr_fd("minishell: export: '", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		return ;
	}
	val = NULL;
	equal = ft_strchr(str, '=');
	if (equal)
	{
		size = equal - str;
		val = ft_substr(str, size + 1, ft_strlen(str));
	}
	else
		size = ft_strlen(str);
	key = get_key(str, size);
	update_export(key, val, env);
}

void	print_export(t_env *env)
{
	t_enode	*node;

	node = env->head->next;
	while (node)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(node->key, STDOUT_FILENO);
		if (node->val)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(node->val, STDOUT_FILENO);
			ft_putchar_fd('"', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		node = node->next;
	}
}

int	builtin_export(int argc, char *argv[], t_env *env)
{
	if (argc == 1)
	{
		print_export(env);
		return (0);
	}
	while (--argc)
		add_export(*++argv, env);
	env->exit_code = EXIT_SUCCESS;
	return (0);
}
