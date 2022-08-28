/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruction2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 08:27:48 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 10:16:59 by yoson            ###   ########.fr       */
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
	c_ra(list_a);
	c_rb(list_b);
}

void	c_rrr(t_list *list_a, t_list *list_b)
{
	c_rra(list_a);
	c_rrb(list_b);
}
