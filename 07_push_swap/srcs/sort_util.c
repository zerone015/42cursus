/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:21:36 by yoson             #+#    #+#             */
/*   Updated: 2022/08/27 22:31:48 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_node *top)
{
	int	ret;

	ret = top->data;
	while (top->next)
	{
		if (ret > top->data)
			ret = top->data;
		top = top->next;
	}
	return (ret);
}

int	get_max(t_node *top)
{
	int	ret;

	ret = top->data;
	while (top->next)
	{
		if (ret < top->data)
			ret = top->data;
		top = top->next;
	}
	return (ret);
}

int	abs_sum(int num1, int num2)
{
	if (num1 < 0)
		num1 *= -1;
	if (num2 < 0)
		num2 *= -1;
	return (num1 + num2);
}

void	three_division(t_list *list_a, t_list *list_b, int size)
{
	t_node	*top_a;
	int		group_size;

	top_a = list_a->head->next;
	group_size = size / 3;
	while (list_a->size > group_size + size % 3)
	{
		if (group_size > top_a->data)
		{
			pb(list_b, remove_first(list_a));
			rb(list_b);
		}
		else if (group_size <= top_a->data && group_size * 2 > top_a->data)
			pb(list_b, remove_first(list_a));
		else
			ra(list_a);
	}
}

void	rotate(t_list *list_a, t_list *list_b, int idx_a, int idx_b)
{
	while ((idx_a > 0 && idx_b > 0) && idx_a-- && idx_b--)
		rr(list_a, list_b);
	while ((idx_a < 0 && idx_b < 0) && idx_a++ && idx_b++)
		rrr(list_a, list_b);
	while (idx_a && idx_a-- > 0)
		ra(list_a);
	while (idx_a && idx_a++ < 0)
		rra(list_a);
	while (idx_b && idx_b-- > 0)
		rb(list_b);
	while (idx_b && idx_b++ < 0)
		rrb(list_b);
}
