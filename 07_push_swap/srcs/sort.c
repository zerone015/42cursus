/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:25:37 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 22:04:13 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
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

static int	find_median(t_list *list, int size)
{
	int		i;
	int		sum;
	t_node	*node;

	node = list->head->next;
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += node->data;
		node = node->next;
		i++;
	}
	return (sum / size);
}

void	a_to_b(t_list *list_a, t_list *list_b, int size)
{
	int		i;
	int		pivot;
	int		ra_cnt;
	int		pb_cnt;

	if (size < 3)
	{
		if (size == 2)
		{
			if (list_a->head->next->data > list_a->head->next->next->data)
				swap(list_a, "sa");
		}
		return ;
	}
	pivot = find_median(list_a, size);
	ra_cnt = 0;
	pb_cnt = 0;
	i = 0;
	while (i < size)
	{
		if (list_a->head->next->data > pivot)
		{
			rotate(list_a, "ra");
			ra_cnt++;
		}
		else
		{
			push(list_b, remove_first(list_a), "pb");
			pb_cnt++;
		}
		i++;
	}
	i = 0;
	while (i < ra_cnt)
	{
		reverse_rotate(list_a, "rra");
		i++;
	}
	a_to_b(list_a, list_b, ra_cnt);
	b_to_a(list_a, list_b, pb_cnt);
}

void	b_to_a(t_list *list_a, t_list *list_b, int size)
{
	int		i;
	int		pivot;
	int		rb_cnt;
	int		pa_cnt;

	if (size < 3)
	{
		if (size == 2)
		{
			if (list_b->head->next->data > list_b->head->next->next->data)
				swap(list_a, "sb");
		}
		push(list_a, remove_first(list_b), "pa");
		return ;
	}
	pivot = find_median(list_b, size);
	rb_cnt = 0;
	pa_cnt = 0;
	i = 0;
	while (i < size)
	{
		if (list_b->head->next->data > pivot)
		{
			rotate(list_b, "rb");
			rb_cnt++;
		}
		else
		{
			push(list_a, remove_first(list_b), "pa");
			pa_cnt++;
		}
		i++;
	}
	i = 0;
	while (i < rb_cnt)
	{
		reverse_rotate(list_b, "rrb");
		i++;
	}
	a_to_b(list_a, list_b, pa_cnt);
	b_to_a(list_a, list_b, list_b->num_cnt);
}

void	sort_by_ascending(t_list *list_a)
{
	t_list	list_b;

	if (is_already_sorted(list_a) == TRUE)
		return ;
	list_init(&list_b);
	a_to_b(list_a, &list_b, list_a->num_cnt);
	int i = -1;
	while (++i < 5)
	{
		printf("%d \n", remove_first(list_a));
	}
}
