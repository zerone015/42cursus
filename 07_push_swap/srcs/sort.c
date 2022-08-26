/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:25:37 by yoson             #+#    #+#             */
/*   Updated: 2022/08/27 05:52:45 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_already_sorted(t_list *list_a)
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

static void	num_init(int num[], t_list *list)
{
	num[0] = list->head->next->data;
	num[1] = list->head->next->next->data;
	num[2] = list->head->next->next->next->data;
	if (num[0] > num[1])
		ft_swap(num, 0, 1);
	if (num[1] > num[2])
		ft_swap(num, 1, 2);
	if (num[0] > num[1])
		ft_swap(num, 0, 1);
}

static void	sort_three(t_list *list)
{
	int	n[3];

	num_init(n, list);
	if (list->head->next->data == n[0] && list->head->next->next->data == n[2])
	{
		reverse_rotate(list, "rra");
		swap(list, "sa");
	}
	else if (list->head->next->data == n[1])
	{
		if (list->head->next->next->data == n[0])
			swap(list, "sa");
		else
			reverse_rotate(list, "rra");
	}
	else if (list->head->next->data == n[2])
	{
		if (list->head->next->next->data == n[0])
			rotate(list, "ra");
		else
		{
			swap(list, "sa");
			reverse_rotate(list, "rra");
		}
	}
}

static void	a_to_b(t_list *list_a, t_list *list_b, int size)
{
	while (list_a->num_cnt > size / 3 + size % 3)
	{
		if (size / 3 > list_a->head->next->data)
		{
			push(list_b, remove_first(list_a), "pb");
			rotate(list_b, "rb");
		}
		else if (size / 3 * 2 + size % 3 <= list_a->head->next->data)
			push(list_b, remove_first(list_a), "pb");
		else
			rotate(list_a, "ra");
	}
	while (list_a->num_cnt > 3)
		push(list_b, remove_first(list_a), "pb");
	if (list_a->num_cnt == 2)
	{
		if (list_a->head->next->data > list_a->head->next->next->data)
			swap(list_a, "sa");
	}
	else
		sort_three(list_a);
}

void	target_to_top(t_list *list, int idx, char *name)
{
	if (list->num_cnt / 2 < idx)
	{
		idx = list->num_cnt - idx;
		while (idx-- > 0)
			reverse_rotate(list, ft_strjoin("rr", name));
	}
	else
	{
		while (idx-- > 0)
			rotate(list, ft_strjoin("r", name));
	}
}

int	is_find(t_node *a, t_node *b, t_node *a_last)
{
	if (!a->prev->prev)
	{
		if (b->data > a_last->data || b->data < a->data)
			return (TRUE);
		if (b->data > a->data && b->data < a->next->data)
			return (TRUE);
	}
	else
	{
		if (a->prev->data < b->data && a->data > b->data)
			return (TRUE);
		if (!a->next->next)
			return (TRUE);
	}
	return (FALSE);
}

void	target_to_a(t_list *list_a, t_list *list_b)
{
	int		idx;
	t_node	*cur;

	cur = list_a->head->next;
	idx = 0;
	while (cur->next)
	{
		if (is_find(cur, list_b->head->next, list_a->tail->prev) == TRUE)
			break;
		cur = cur->next;
		idx++;
	}
	target_to_top(list_a, idx, "a");
	push(list_a, remove_first(list_b), "pa");
	if (idx == 0 && list_a->head->next->data > list_a->tail->prev->data)
		rotate(list_a, "ra");
	else if (idx == 0 && list_a->head->next->data > list_a->head->next->next->data)
		swap(list_a, "sa");
	if (list_a->num_cnt / 2 < idx)
	{
		idx = list_a->num_cnt - idx;
		while (idx-- > 0)
			rotate(list_a, "ra");
	}
	else
	{
		while (idx-- > 0)
			reverse_rotate(list_a, "rra");
	}
}

int	get_inst_cnt(int a_idx, int b_idx, int a_size, int b_size)
{
	if (a_size / 2 < a_idx)
		a_idx = a_size - a_idx;
	if (b_size / 2 < b_idx)
		b_idx = b_size - b_idx;
	return (a_idx + b_idx);
}
/*
3	6
4	7
5	8
	9
	0
	1
	2
*/
int	find_best_target(t_node *a, t_node *b, t_list *la, t_list *lb)
{
	int	a_idx;
	int	b_idx;
	int	min_inst;
	int	min_idx;

	b_idx = -1;
	while (++b_idx < lb->num_cnt)
	{
		a_idx = -1;
		while (++a_idx < la->num_cnt)
		{
			if (is_find(a, b, la->tail->prev) == TRUE)
				break ;
			a = a->next;
		}
		if (b_idx == 0 || min_inst > get_inst_cnt(a_idx, b_idx, la->num_cnt, lb->num_cnt))
		{
			min_inst = get_inst_cnt(a_idx, b_idx, la->num_cnt, lb->num_cnt);
			min_idx = b_idx;
		}
		a = la->head->next;
		b = b->next;
	}
	return (min_idx);
}

void	sort_by_ascending(t_list *list_a, t_list *list_b)
{
	int	idx;

	if (is_already_sorted(list_a) == TRUE)
		return ;
	a_to_b(list_a, list_b, list_a->num_cnt);
	while (list_b->num_cnt)
	{
		idx = find_best_target(list_a->head->next, list_b->head->next, list_a, list_b);
		target_to_top(list_b, idx, "b");
		target_to_a(list_a, list_b);
	}
}
