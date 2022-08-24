/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:47:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 18:07:15 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *list, char *str)
{
	int	temp;

	temp = list->head->next->data;
	list->head->next->data = list->head->next->next->data;
	list->head->next->next->data = temp;
	ft_putendl_fd(str, 1);
}

void	push(t_list *list, int data, char *str)
{
	add_first(list, data);
	ft_putendl_fd(str, 1);
}

void	rotate(t_list *list, char *str)
{
	list->tail->prev->next = list->head->next;
	list->head->next = list->head->next->next;
	list->head->next->prev = list->head;
	list->tail->prev->next->prev = list->tail->prev;
	list->tail->prev->next->next = list->tail;
	list->tail->prev = list->tail->prev->next;
	ft_putendl_fd(str, 1);
}

void	reverse_rotate(t_list *list, char *str)
{
	list->head->next->prev = list->tail->prev;
	list->tail->prev = list->tail->prev->prev;
	list->tail->prev->next = list->tail;
	list->head->next->prev->next = list->head->next;
	list->head->next->prev->prev = list->head;
	list->head->next = list->head->next->prev;
	ft_putendl_fd(str, 1);
}
