/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:09:19 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 06:26:54 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *list)
{
	t_node	*temp;

	temp = list->head->next;
	list->head->next = list->head->next->next;
	list->head->next->prev = list->head;
	temp->prev = list->tail->prev;
	temp->next = list->tail;
	list->tail->prev->next = temp;
	list->tail->prev = temp;
	ft_putendl_fd("ra", 1);
}

void	rb(t_list *list)
{
	t_node	*temp;

	temp = list->head->next;
	list->head->next = list->head->next->next;
	list->head->next->prev = list->head;
	temp->prev = list->tail->prev;
	temp->next = list->tail;
	list->tail->prev->next = temp;
	list->tail->prev = temp;
	ft_putendl_fd("rb", 1);
}

void	rra(t_list *list)
{
	t_node	*temp;

	temp = list->tail->prev;
	list->tail->prev = list->tail->prev->prev;
	list->tail->prev->next = list->tail;
	temp->prev = list->head;
	temp->next = list->head->next;
	list->head->next->prev = temp;
	list->head->next = temp;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list *list)
{
	t_node	*temp;

	temp = list->tail->prev;
	list->tail->prev = list->tail->prev->prev;
	list->tail->prev->next = list->tail;
	temp->prev = list->head;
	temp->next = list->head->next;
	list->head->next->prev = temp;
	list->head->next = temp;
	ft_putendl_fd("rrb", 1);
}
