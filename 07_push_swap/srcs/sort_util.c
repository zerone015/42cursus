/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:21:36 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 21:55:40 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_sum(int num1, int num2)
{
	if (num1 < 0)
		num1 *= -1;
	if (num2 < 0)
		num2 *= -1;
	return (num1 + num2);
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
