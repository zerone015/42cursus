/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:26:08 by yoson             #+#    #+#             */
/*   Updated: 2022/08/17 19:04:39 by yoson            ###   ########.fr       */
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

void	add_first(t_deque *deque, int num)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		error("Error");
	new_node->num = num;
	new_node->prev = deque->head;
	new_node->next = deque->head->next;
	deque->head->next->prev = new_node;
	deque->head->next = new_node;
	(deque->num_cnt)++;
}

void	add_last(t_deque *deque, int num)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		error("Error");
	new_node->num = num;
	new_node->prev = deque->tail->prev;
	new_node->next = deque->tail;
	deque->tail->prev->next = new_node;
	deque->tail->prev = new_node;
	(deque->num_cnt)++;
}

int	remove_first(t_deque *deque)
{
	t_node	*r_node;
	int		r_num;

	if (deque->num_cnt == 0)
		error("Error");
	r_node = deque->head->next;
	r_num = deque->head->next->num;
	deque->head->next = deque->head->next->next;
	free(r_node);
	deque->head->next->prev = deque->head;
	(deque->num_cnt)--;
	return (r_num);
}

int	remove_last(t_deque *deque)
{
	t_node	*r_node;
	int		r_num;

	if (deque->num_cnt == 0)
		error("Error");
	r_node = deque->tail->prev;
	r_num = deque->tail->prev->num;
	deque->tail->prev = deque->tail->prev->prev;
	free(r_node);
	deque->tail->prev->next = deque->tail;
	(deque->num_cnt)--;
	return (r_num);
}
