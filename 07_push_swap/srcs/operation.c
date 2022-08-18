/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:47:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 07:11:54 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque *deque, char *str)
{
	int	temp;

	temp = deque->head->next->data;
	deque->head->next->data = deque->head->next->next->data;
	deque->head->next->next->data = temp;
	ft_putendl_fd(str, 1);
}

void	push(t_deque *deque, int data, char *str)
{
	add_first(deque, data);
	ft_putendl_fd(str, 1);
}

void	rotate(t_deque *deque, char *str)
{
	deque->tail->prev->next = deque->head->next;
	deque->head->next = deque->head->next->next;
	deque->head->next->prev = deque->head;
	deque->tail->prev->next->prev = deque->tail->prev;
	deque->tail->prev->next->next = deque->tail;
	deque->tail->prev = deque->tail->prev->next;
	ft_putendl_fd(str, 1);
}

void	reverse_rotate(t_deque *deque, char *str)
{
	deque->head->next->prev = deque->tail->prev;
	deque->tail->prev = deque->tail->prev->prev;
	deque->tail->prev->next = deque->tail;
	deque->head->next->prev->next = deque->head->next;
	deque->head->next->prev->prev = deque->head;
	deque->head->next = deque->head->next->prev;
	ft_putendl_fd(str, 1);
}
