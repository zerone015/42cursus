/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sprrrrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:47:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/27 17:10:25 by yoson            ###   ########.fr       */
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
	add_last(list_a, remove_first(list_a));
	add_last(list_b, remove_first(list_b));
	ft_putendl_fd("rr", 1);
}

void	rrr(t_list *list_a, t_list *list_b)
{	
	add_first(list_a, remove_last(list_a));
	add_first(list_b, remove_last(list_b));
	ft_putendl_fd("rrr", 1);
}
