/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:47:58 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 21:54:39 by kijsong          ###   ########.fr       */
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
		node->val = val;
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
		ft_putstr_fd("export: '", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd("': not a valid identifier", 2);
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
		ft_putstr_fd(node->key, 1);
		if (node->key)
		{
			ft_putchar_fd('=', 1);
			ft_putstr_fd(node->val, 1);
		}
		node = node->next;
	}
}

void	builtin_export(int argc, char *argv[], t_env *env)
{
	if (argc == 1)
	{
		print_export(env);
		return ;
	}
	while (--argc)
		add_export(*++argv, env);
}
