/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:26:08 by yoson             #+#    #+#             */
/*   Updated: 2022/08/13 03:28:35 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	list_init(t_list *list)
{
	t_node	*dummy_node;

	dummy_node = (t_node *) malloc(sizeof(t_node));
	if (!dummy_node)
		error("Error");
	dummy_node->next = NULL;
	list->head = dummy_node;
	list->tail = dummy_node;
}

void	l_insert(t_list *list, int num)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		error("Error");
	new_node->num = num;
	new_node->next = NULL;
	list->tail->next = new_node;
	list->tail = new_node;
}
