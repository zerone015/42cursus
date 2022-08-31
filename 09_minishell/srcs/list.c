/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:11:19 by yoson             #+#    #+#             */
/*   Updated: 2022/08/31 19:04:28 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*init_list(void)
{
	t_list	*env;

	env = safe_malloc(sizeof(t_list));
	env->head = safe_malloc(sizeof(t_lnode));
	env->tail = env->head;
	return (env);
}

void	add_last(t_list *env, char *key, char *val)
{
	t_lnode	*new;

	new = safe_malloc(sizeof(t_lnode));
	new->key = key;
	new->val = val;
	new->next = NULL;
	env->tail->next = new;
	env->tail = new;
}

t_lnode	*find_key(t_list *env, char *key)
{
	t_lnode	*node;

	node = env->head->next;
	while (node)
	{
		if (ft_strcmp(node->key, key) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
