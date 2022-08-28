/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:25:37 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 22:48:32 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_already_sorted(t_list *list_a)
{
	t_node	*node;

	node = list_a->head->next;
	while (node->next->next)
	{
		if (node->data > node->next->data)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

void	sort_three(t_list *list)
{
	int	top;
	int	mid;
	int	btm;

	top = list->head->next->data;
	mid = list->head->next->next->data;
	btm = list->head->next->next->next->data;
	if (mid > top && mid > btm && btm > top)
	{
		sa(list);
		ra(list);
	}
	else if (top > mid && mid > btm && top > btm)
	{
		sa(list);
		rra(list);
	}
	else if (top > mid && btm > mid && btm > top)
		sa(list);
	else if (mid > top && mid > btm && top > btm)
		rra(list);
	else if (top > mid && btm > mid && top > btm)
		ra(list);
}

void	three_division(t_list *list_a, t_list *list_b, int size)
{
	int		top_idx;
	int		group_size;

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

void	b_to_a(t_list *list_a, t_list *list_b, t_node *node_b)
{
	int		i;
	int		idx_a;
	int		idx_b;
	int		min_a;
	int		min_b;

	i = -1;
	while (++i < list_b->size)
	{
		idx_a = find_location(list_a, node_b->data);
		if (i >= (list_b->size + 1) / 2)
			idx_b = (list_b->size - i) * -1;
		else
			idx_b = i;
		if (i == 0 || abs_sum(min_a, min_b) > abs_sum(idx_a, idx_b))
		{
			min_a = idx_a;
			min_b = idx_b;
		}
		node_b = node_b->next;
	}
	rotate(list_a, list_b, min_a, min_b);
	pa(list_a, remove_first(list_b));
	update_min_max(list_a);
}

void	sort(t_list *list_a)
{
	t_list	*list_b;

	if (list_a->size == 3)
		sort_three(list_a);
	if (is_already_sorted(list_a) == TRUE)
		return ;
	list_init(&list_b);
	three_division(list_a, list_b, list_a->size);
	while (list_a->size > 3)
		pb(list_b, remove_first(list_a));
	if (list_a->size == 2)
	{
		if (list_a->head->next->data > list_a->tail->prev->data)
			sa(list_a);
	}
	if (list_a->size == 3)
		sort_three(list_a);
	list_a->min = list_a->head->next->data;
	list_a->max = list_a->tail->prev->data;
	while (list_b->size > 0)
		b_to_a(list_a, list_b, list_b->head->next);
	last_sort(list_a);
	list_free(list_b);
}
