/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:11:19 by yoson             #+#    #+#             */
/*   Updated: 2022/11/19 22:48:20 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/minishell.h"

t_env	*init_env(void)
{
	t_env	*env;

	env = safe_malloc(sizeof(t_env));
	env->head = safe_malloc(sizeof(t_enode));
	env->tail = env->head;
	env->exit_code = 0;
	return (env);
}

void	add_enode(t_env *env, char *key, char *val)
{
	t_enode	*new;

	new = safe_malloc(sizeof(t_enode));
	new->key = key;
	new->val = val;
	new->next = NULL;
	env->tail->next = new;
	env->tail = new;
}

t_enode	*find_key(t_env *env, char *key)
{
	t_enode	*node;

	node = env->head->next;
	while (node)
	{
		if (ft_strcmp(node->key, key) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	delete_enode(t_env *env, t_enode *prev, t_enode *curr)
{
	prev->next = curr->next;
	if (env->tail == curr)
		env->tail = prev;
	free(curr->key);
	free(curr->val);
	free(curr);
}

int	count_env(t_env *env)
{
	int		size;
	t_enode	*node;

	size = 0;
	node = env->head->next;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
