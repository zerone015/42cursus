/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:21:36 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 01:36:27 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_location(t_list *list_a, int num)
{
	int	ret;

	if (num < get_min(list_a->head->next))
		ret = find_location_min(list_a);
	else if (num > get_max(list_a->head->next))
		ret = find_location_max(list_a);
	else
		ret = find_location_mid(list_a, num);
	return (ret);
}

void	three_division(t_list *list_a, t_list *list_b, int size)
{
	int	top_idx;
	int	group_size;

	top_idx = list_a->head->next->data;
	group_size = size / 3;
	while (list_a->size > group_size + size % 3)
	{
		if (group_size > top_idx)
		{
			pb(list_b, remove_first(list_a));
			rb(list_b);
		}
		else if (group_size <= top_idx && group_size * 2 > top_idx)
			pb(list_b, remove_first(list_a));
		else
			ra(list_a);
		top_idx = list_a->head->next->data;
	}
}

void	rotate(t_list *list_a, t_list *list_b, int idx_a, int idx_b)
{
	while ((idx_a > 0 && idx_b > 0) && idx_a-- && idx_b--)
		rr(list_a, list_b);
	while ((idx_a < 0 && idx_b < 0) && idx_a++ && idx_b++)
		rrr(list_a, list_b);
	while (idx_a > 0)
	{
		ra(list_a);
		idx_a--;
	}
	while (idx_a < 0)
	{
		rra(list_a);
		idx_a++;
	}
	while (idx_b > 0)
	{
		rb(list_b);
		idx_b--;
	}
	while (idx_b < 0)
	{
		rrb(list_b);
		idx_b++;
	}
}

void	last_sort(t_list *list_a)
{
	int		idx;

	idx = find_location_min(list_a);
	while (idx)
	{
		if (idx > 0)
		{
			ra(list_a);
			idx--;
		}
		else
		{
			rra(list_a);
			idx++;
		}
	}
}

int	abs_sum(int num1, int num2)
{
	if (num1 < 0)
		num1 *= -1;
	if (num2 < 0)
		num2 *= -1;
	return (num1 + num2);
}
