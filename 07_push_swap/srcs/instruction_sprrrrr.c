/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sprrrrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:47:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 06:29:30 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list)
{
	int	temp;

	temp = list->head->next->data;
	list->head->next->data = list->head->next->next->data;
	list->head->next->next->data = temp;
	ft_putendl_fd("sa", 1);
}

void	pa(t_list *list, int data)
{
	add_first(list, data);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list *list, int data)
{
	add_first(list, data);
	ft_putendl_fd("pb", 1);
}

void	rr(t_list *list_a, t_list *list_b)
{	
	t_node	*temp;

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
	ft_putendl_fd("rr", 1);
}

void	rrr(t_list *list_a, t_list *list_b)
{	
	t_node	*temp;

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
	ft_putendl_fd("rrr", 1);
}
