/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:04:11 by yoson             #+#    #+#             */
/*   Updated: 2022/08/23 22:05:55 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	insert_numbers_to_temp(int temp[], t_deque *deque_a)
{
	int		i;
	t_node	*node;

	node = deque_a->head->next;
	i = 0;
	while (i < deque_a->num_cnt)
	{
		temp[i] = node->data;
		node = node->next;
		i++;
	}
}

static int	duplicate_number_exists(int temp[], t_deque *deque_a)
{
	int	i;

	i = 0;
	while (i < deque_a->num_cnt - 1)
	{
		if (temp[i] == temp[i + 1])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	renumbering(int temp[], t_deque *deque_a)
{
	int		node_cnt;
	t_node	*node;

	node = deque_a->head->next;
	node_cnt = deque_a->num_cnt;
	while (node_cnt--)
	{
		node->data = binary_search(temp, node->data);
		node = node->next;
	}
}

void	preprocess(t_deque *deque_a)
{
	int		*temp;

	temp = (int *) malloc(sizeof(int) * deque_a->num_cnt);
	insert_numbers_to_temp(temp, deque_a);
	quick_sort(temp, 0, deque_a->num_cnt - 1);
	if (duplicate_number_exists(temp, deque_a) == TRUE)
		error("Error");
	renumbering(temp, deque_a);
}
