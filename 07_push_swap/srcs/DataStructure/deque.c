/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:26:08 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 07:10:33 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdlib.h>

void	deque_init(t_deque *deque)
{
	deque->head = (t_node *) malloc(sizeof(t_node));
	deque->tail = (t_node *) malloc(sizeof(t_node));
	if (!deque->head || !deque->tail)
		error("Error");
	deque->head->prev = NULL;
	deque->head->next = deque->tail;
	deque->tail->next = NULL;
	deque->tail->prev = deque->head;
	deque->num_cnt = 0;
}

void	add_first(t_deque *deque, int data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		error("Error");
	new_node->data = data;
	new_node->prev = deque->head;
	new_node->next = deque->head->next;
	deque->head->next->prev = new_node;
	deque->head->next = new_node;
	(deque->num_cnt)++;
}

void	add_last(t_deque *deque, int data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		error("Error");
	new_node->data = data;
	new_node->prev = deque->tail->prev;
	new_node->next = deque->tail;
	deque->tail->prev->next = new_node;
	deque->tail->prev = new_node;
	(deque->num_cnt)++;
}

int	remove_first(t_deque *deque)
{
	t_node	*r_node;
	int		r_data;

	if (deque->num_cnt == 0)
		error("Error");
	r_node = deque->head->next;
	r_data = deque->head->next->data;
	deque->head->next = deque->head->next->next;
	free(r_node);
	deque->head->next->prev = deque->head;
	(deque->num_cnt)--;
	return (r_data);
}

int	remove_last(t_deque *deque)
{
	t_node	*r_node;
	int		r_data;

	if (deque->num_cnt == 0)
		error("Error");
	r_node = deque->tail->prev;
	r_data = deque->tail->prev->data;
	deque->tail->prev = deque->tail->prev->prev;
	free(r_node);
	deque->tail->prev->next = deque->tail;
	(deque->num_cnt)--;
	return (r_data);
}
