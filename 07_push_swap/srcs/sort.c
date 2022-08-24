/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:25:37 by yoson             #+#    #+#             */
/*   Updated: 2022/08/25 00:17:14 by yoson            ###   ########.fr       */
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

	if (size == 0)
		return (-1);
	node = list->head->next;
	sum = 0;
	i = 0;
	while (i < size)
	{
		if (!node)
			return (-1);
		sum += node->data;
		node = node->next;
		i++;
	}
	return (sum / size);
}


void	show_list(t_list *a, t_list *b)
{
	t_node *node;

	ft_putstr_fd("\na: ", 1);
	node = a->head->next;
	while (node->next)
	{
		ft_putnbr_fd(node->data, 1);
		write(1, " ", 1);
		node = node->next;
	}
	node = b->head->next;
	ft_putstr_fd("\nb: ", 1);
	while (node->next)
	{
		ft_putnbr_fd(node->data, 1);
		write(1, " ", 1);
		node = node->next;
	}
	write(1, "\n\n", 2);
}

void	a_to_b(t_list *list_a, t_list *list_b, int size)
{
	int		i;
	int		pivot;
	int		ra_cnt;
	int		pb_cnt;

	if (size == 1)
		return ;
	pivot = find_median(list_a, size);
	if (pivot == -1)
		return ;
	ra_cnt = 0;
	pb_cnt = 0;
	i = 0;
	while (i < size)
	{
		if (list_a->head->next->data > pivot)
		{
			ft_putnbr_fd(list_a->head->next->data, 1);
			write(1, " = ", 3);
			rotate(list_a, "ra");
			ra_cnt++;
		}
		else
		{
			ft_putnbr_fd(list_a->head->next->data, 1);
			write(1, " = ", 3);
			push(list_b, remove_first(list_a), "pb");
			pb_cnt++;
		}
		i++;
	}
	i = 0;
	while (i < ra_cnt)
	{
		ft_putnbr_fd(list_a->tail->prev->data, 1);
		write(1, " = ", 3);
		reverse_rotate(list_a, "rra");
		i++;
	}
	show_list(list_a, list_b);
	a_to_b(list_a, list_b, ra_cnt);
	b_to_a(list_a, list_b, pb_cnt);
}

void	b_to_a(t_list *list_a, t_list *list_b, int size)
{
	int		i;
	int		pivot;
	int		rb_cnt;
	int		pa_cnt;

	if (size == 1)
	{
		ft_putnbr_fd(list_b->head->next->data, 1);
		write(1, " = ", 3);
		push(list_a, remove_first(list_b), "pa");
		return ;
	}
	pivot = find_median(list_b, size);
	if (pivot == -1)
		return ;
	rb_cnt = 0;
	pa_cnt = 0;
	i = 0;
	while (i < size)
	{
		if (list_b->head->next->data <= pivot)
		{
			ft_putnbr_fd(list_b->head->next->data, 1);
			write(1, " = ", 3);
			rotate(list_b, "rb");
			rb_cnt++;
		}
		else
		{
			ft_putnbr_fd(list_b->head->next->data, 1);
			write(1, " = ", 3);
			push(list_a, remove_first(list_b), "pa");
			pa_cnt++;
		}
		i++;
	}
	i = 0;
	while (i < rb_cnt)
	{
		ft_putnbr_fd(list_b->tail->prev->data, 1);
		write(1, " = ", 3);
		reverse_rotate(list_b, "rrb");
		i++;
	}
	show_list(list_a, list_b);
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
	show_list(list_a, &list_b);
}
