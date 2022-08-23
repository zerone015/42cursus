/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:25:37 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 02:36:08 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_already_sorted(t_deque *deque_a)
{
	t_node	*node;

	node = deque_a->head->next;
	while (node->next)
	{
		if (node->data > node->next->data)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

static int	find_median(t_deque *deque)
{
	int		mid;
	t_node	*node;

	node = deque->head->next;
	mid = deque->num_cnt / 2;
	while (node)
	{
		if (node->data == mid)
			break ;
		node = node->next;
	}
	return (node->data);
}

static void	a_to_b(t_deque *deque_a, t_deque *deque_b, int ra_cnt)
{
	int		i;
	int		pivot;
	int		pb_cnt;
	t_node	*node;

	if (deque_a->num_cnt == 1)
		return ;
	pivot = find_median(deque_a);
	node = deque_a->head->next;
	pb_cnt = 0;
	i = 0;
	while (i < deque_a->num_cnt)
	{
		if (node->data > pivot)
		{
			rotate(deque_a, "ra");
			ra_cnt++;
		}
		else
		{
			push(deque_b, remove_first(deque_a), "pb");
			pb_cnt++;
		}
	}
	i = 0;
	while (i < ra_cnt)
	{
		reverse_rotate(deque_a, "rra");
		i++;
	}
	a_to_b(deque_a, deque_b, ra_cnt);
	b_to_a(deque_a, deque_b, pb_cnt);
}

static void	b_to_a(t_deque *deque_a, t_deque *deque_b, int pb_cnt)
{
	int		i;
	int		pivot;
	int		rb_cnt;
	int		pa_cnt;
	t_node	*node;

	if (deque_b->num_cnt == 1)
	{
		push(deque_a, remove_first(deque_b), "pa");
		return ;
	}
	pivot = find_median(deque_b);
	node = deque_b->head->next;
	rb_cnt = 0;
	pa_cnt = 0;
	i = 0;
	while (i < deque_b->num_cnt)
	{
		if (node->data > pivot)
		{
			rotate(deque_b, "rb");
			rb_cnt++;
		}
		else
		{
			push(deque_a, remove_first(deque_b), "pa");
			pa_cnt++;
		}
	}
	i = 0;
	while (i < rb_cnt)
	{
		reverse_rotate(deque_b, "rrb");
		i++;
	}
	a_to_b(deque_a, deque_b, pa_cnt);
	b_to_a(deque_a, deque_b, pb_cnt);
}

void	sort_by_ascending(t_deque *deque_a)
{
	t_deque	deque_b;

	if (is_already_sorted(deque_a) == TRUE)
		return ;
	deque_init(&deque_b);
	a_to_b(deque_a, &deque_b, 0, 0);
}
