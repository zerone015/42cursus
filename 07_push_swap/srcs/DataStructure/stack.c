/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:18:18 by yoson             #+#    #+#             */
/*   Updated: 2022/08/13 03:30:13 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	stack_init(t_stack *stack)
{
	stack->head = NULL;
}

int	s_push(t_stack *stack, int result)
{
	t_node	*new_node;

	*new_node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		error("Error");
	new_node->num = result;
	new_node->next = stack->head;
	stack->head = new_node;
}
