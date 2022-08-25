/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:25:37 by yoson             #+#    #+#             */
/*   Updated: 2022/08/26 01:36:05 by yoson            ###   ########.fr       */
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

void	sort_by_ascending(t_list *list_a, t_list *list_b)
{
	if (is_already_sorted(list_a) == TRUE)
		return ;
	a_to_b(list_a, list_b, list_a->num_cnt);
	while (list_b->num_cnt)
		b_to_a(list_a, list_b, find_best_case(list_a, list_b));
}
