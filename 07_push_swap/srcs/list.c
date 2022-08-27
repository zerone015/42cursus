/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:26:08 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 06:44:41 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	list_init(t_list **list)
{
	*list = (t_list *) malloc(sizeof(t_list));
	if (!*list)
		error("Error");
	(*list)->head = (t_node *) malloc(sizeof(t_node));
	(*list)->tail = (t_node *) malloc(sizeof(t_node));
	if (!(*list)->head || !(*list)->tail)
		error("Error");
	(*list)->head->prev = NULL;
	(*list)->head->next = (*list)->tail;
	(*list)->tail->next = NULL;
	(*list)->tail->prev = (*list)->head;
	(*list)->size = 0;
}

void	add_first(t_list *list, int data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		error("Error");
	new_node->data = data;
	new_node->prev = list->head;
	new_node->next = list->head->next;
	list->head->next->prev = new_node;
	list->head->next = new_node;
	(list->size)++;
}

void	add_last(t_list *list, int data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		error("Error");
	new_node->data = data;
	new_node->prev = list->tail->prev;
	new_node->next = list->tail;
	list->tail->prev->next = new_node;
	list->tail->prev = new_node;
	(list->size)++;
}

int	remove_first(t_list *list)
{
	t_node	*r_node;
	int		r_data;

	if (list->size == 0)
		error("Error");
	r_node = list->head->next;
	r_data = list->head->next->data;
	list->head->next = list->head->next->next;
	free(r_node);
	list->head->next->prev = list->head;
	(list->size)--;
	return (r_data);
}

void	list_free(t_list *list)
{
	t_node	*temp;

	while (list->head)
	{
		temp = list->head->next;
		free(list->head);
		list->head = temp;
	}
	free(list);
}
