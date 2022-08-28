/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruction2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 08:27:48 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 09:57:12 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	c_sb(t_list *list)
{
	int	temp;

	if (list->size < 2)
		return ;
	temp = list->head->next->data;
	list->head->next->data = list->head->next->next->data;
	list->head->next->next->data = temp;
}

void	c_pa(t_list *list, int data)
{
	if (data != -1)
		add_first(list, data);
}

void	c_pb(t_list *list, int data)
{
	if (data != -1)
		add_first(list, data);
}

void	c_rr(t_list *list_a, t_list *list_b)
{
	t_node	*temp;

	if (list_a->size == 0 || list_b->size == 0)
		return ;
	temp = list_a->head->next;
	list_a->head->next = list_a->head->next->next;
	list_a->head->next->prev = list_a->head;
	temp->prev = list_a->tail->prev;
	temp->next = list_a->tail;
	list_a->tail->prev->next = temp;
	list_a->tail->prev = temp;
	temp = list_b->head->next;
	list_b->head->next = list_b->head->next->next;
	list_b->head->next->prev = list_b->head;
	temp->prev = list_b->tail->prev;
	temp->next = list_b->tail;
	list_b->tail->prev->next = temp;
	list_b->tail->prev = temp;
}

void	c_rrr(t_list *list_a, t_list *list_b)
{
	t_node	*temp;

	if (list_a->size == 0 || list_b->size == 0)
		return ;
	temp = list_a->tail->prev;
	list_a->tail->prev = list_a->tail->prev->prev;
	list_a->tail->prev->next = list_a->tail;
	temp->prev = list_a->head;
	temp->next = list_a->head->next;
	list_a->head->next->prev = temp;
	list_a->head->next = temp;
	temp = list_b->tail->prev;
	list_b->tail->prev = list_b->tail->prev->prev;
	list_b->tail->prev->next = list_b->tail;
	temp->prev = list_b->head;
	temp->next = list_b->head->next;
	list_b->head->next->prev = temp;
	list_b->head->next = temp;
}
