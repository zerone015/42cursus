/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:04:11 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 02:35:31 by yoson            ###   ########.fr       */
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

static int	duplicate_number_exists(int temp[], int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (temp[i] == temp[i + 1])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	renumbering(int temp[], t_deque *deque_a)
{
	int		i;
	int		num_cnt;
	t_node	*node;

	node = deque_a->head->next;
	num_cnt = deque_a->num_cnt;
	i = 0;
	while (i < num_cnt)
	{
		node->data = interpolation_search(temp, 0, num_cnt, node->data);
		node = node->next;
		i++;
	}
}

void	preprocess(t_deque *deque_a)
{
	int		*temp;

	temp = (int *) malloc(sizeof(int) * deque_a->num_cnt);
	if (!temp)
		error("Error");
	insert_numbers_to_temp(temp, deque_a);
	quick_sort(temp, 0, deque_a->num_cnt - 1);
	if (duplicate_number_exists(temp, deque_a->num_cnt) == TRUE)
		error("Error");
	renumbering(temp, deque_a);
	free(temp);
}
