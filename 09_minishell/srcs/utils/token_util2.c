/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:43:13 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/04 15:26:52 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../../includes/token.h"

void	push(t_tnode *node, t_token *stack)
{
	node->next = stack->head->next;
	stack->head->next = node;
	if (!node->next)
		stack->tail = node;
}

void	push_back(t_tnode *node, t_token *stack)
{
	node->next = NULL;
	stack->tail->next = node;
	stack->tail = node;
}

t_tnode	*pop(t_token *stack)
{
	t_tnode	*top;

	top = stack->head->next;
	if (!top)
		return (NULL);
	stack->head->next = top->next;
	if (stack->tail == top)
		stack->tail = NULL;
	top->next = NULL;
	return (top);
}
