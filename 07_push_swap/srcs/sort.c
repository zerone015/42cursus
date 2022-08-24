/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:25:37 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 17:48:10 by yoson            ###   ########.fr       */
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

static int	find_median(t_list *list)
{
	int		mid;
	t_node	*node;

	node = list->head->next;
	mid = list->num_cnt / 2;
	while (node->next)
	{
		if (node->data == mid)
			break ;
		node = node->next;
	}
	return (node->data);
}

void	a_to_b(t_list *list_a, t_list *list_b, int ra_cnt)
{
	int		i;
	int		pivot;
	int		pb_cnt;
	t_node	*node;

	if (list_a->num_cnt == 1)
		return ;
	pivot = find_median(list_a);
	node = list_a->head->next;
	pb_cnt = 0;
	i = 0;
	while (i < list_a->num_cnt)
	{
		if (node->data > pivot)
		{
			rotate(list_a, "ra");
			ra_cnt++;
		}
		else
		{
			push(list_b, remove_first(list_a), "pb");
			pb_cnt++;
		}
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

void	b_to_a(t_list *list_a, t_list *list_b, int pb_cnt)
{
	int		i;
	int		pivot;
	int		rb_cnt;
	int		pa_cnt;
	t_node	*node;

	if (list_b->num_cnt == 1)
	{
		push(list_a, remove_first(list_b), "pa");
		return ;
	}
	pivot = find_median(list_b);
	node = list_b->head->next;
	rb_cnt = 0;
	pa_cnt = 0;
	i = 0;
	while (i < list_b->num_cnt)
	{
		if (node->data > pivot)
		{
			rotate(list_b, "rb");
			rb_cnt++;
		}
		else
		{
			push(list_a, remove_first(list_b), "pa");
			pa_cnt++;
		}
	}
	i = 0;
	while (i < rb_cnt)
	{
		reverse_rotate(list_b, "rrb");
		i++;
	}
	a_to_b(list_a, list_b, pa_cnt);
	b_to_a(list_a, list_b, pb_cnt);
}

void	sort_by_ascending(t_list *list_a)
{
	t_list	list_b;

	if (is_already_sorted(list_a) == TRUE)
		return ;
	list_init(&list_b);
	a_to_b(list_a, &list_b, 0);
}
