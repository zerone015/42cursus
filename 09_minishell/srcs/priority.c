/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:44:42 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/30 19:13:49 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_priority(t_tnode *node, int in_stack)
{
	if (!ft_strcmp(node->str, "(") && in_stack)
		return (-1);
	return (node->type);
}

t_token	*infix_to_postfix(t_token *infix)
{
	t_tnode	*node;
	t_token	*postfix;

	node = infix->head;
	while (node)
	{
		if (node->type >= LOGICAL)
		{
			
		}
		node = node->next;
	}
	return (postfix);
}
