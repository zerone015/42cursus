/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 08:17:45 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 09:56:26 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	c_sa(t_list *list)
{
	int	temp;

	if (list->size < 2)
		return ;
	temp = list->head->next->data;
	list->head->next->data = list->head->next->next->data;
	list->head->next->next->data = temp;
}

void	c_ra(t_list *list)
{
	t_node	*temp;

	if (list->size == 0)
		return ;
	temp = list->head->next;
	list->head->next = list->head->next->next;
	list->head->next->prev = list->head;
	temp->prev = list->tail->prev;
	temp->next = list->tail;
	list->tail->prev->next = temp;
	list->tail->prev = temp;
}

void	c_rb(t_list *list)
{
	t_node	*temp;

	if (list->size == 0)
		return ;
	temp = list->head->next;
	list->head->next = list->head->next->next;
	list->head->next->prev = list->head;
	temp->prev = list->tail->prev;
	temp->next = list->tail;
	list->tail->prev->next = temp;
	list->tail->prev = temp;
}

void	c_rra(t_list *list)
{
	t_node	*temp;

	if (list->size == 0)
		return ;
	temp = list->tail->prev;
	list->tail->prev = list->tail->prev->prev;
	list->tail->prev->next = list->tail;
	temp->prev = list->head;
	temp->next = list->head->next;
	list->head->next->prev = temp;
	list->head->next = temp;
}

void	c_rrb(t_list *list)
{
	t_node	*temp;

	if (list->size == 0)
		return ;
	temp = list->tail->prev;
	list->tail->prev = list->tail->prev->prev;
	list->tail->prev->next = list->tail;
	temp->prev = list->head;
	temp->next = list->head->next;
	list->head->next->prev = temp;
	list->head->next = temp;
}
