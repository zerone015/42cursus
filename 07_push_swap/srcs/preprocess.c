/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:04:11 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 20:51:50 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	insert_numbers_to_temp(int temp[], t_list *list_a)
{
	t_node	*node;

	node = list_a->head->next;
	while (node->next)
	{
		*temp = node->data;
		node = node->next;
		temp++;
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

static void	indexing(int temp[], t_list *list_a)
{
	t_node	*node;

	node = list_a->head->next;
	while (node->next)
	{
		node->data = binary_search(temp, list_a->num_cnt, node->data);
		node = node->next;
	}
}

void	preprocess(t_list *list_a)
{
	int		*temp;

	temp = (int *) malloc(sizeof(int) * list_a->num_cnt);
	if (!temp)
		error("Error");
	insert_numbers_to_temp(temp, list_a);
	quick_sort(temp, 0, list_a->num_cnt - 1);
	if (duplicate_number_exists(temp, list_a->num_cnt) == TRUE)
		error("Error");
	indexing(temp, list_a);
	free(temp);
}
