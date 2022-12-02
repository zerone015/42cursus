/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:22:44 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/02 13:58:46 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/priority.h"

int	get_priority(t_tnode *node, int in_stack)
{
	if (!ft_strcmp(node->str, "(") && in_stack)
		return (-1);
	return (node->type);
}

int	get_stack_size(t_token *stack)
{
	int		size;
	t_tnode	*node;

	size = 0;
	node = stack->head->next;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
