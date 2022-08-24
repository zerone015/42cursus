/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:47:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 21:08:52 by yoson            ###   ########.fr       */
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
	add_last(list, remove_first(list));
	ft_putendl_fd(str, 1);
}

void	reverse_rotate(t_list *list, char *str)
{
	add_first(list, remove_last(list));
	ft_putendl_fd(str, 1);
}
