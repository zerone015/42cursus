/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:29:35 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 22:32:34 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_location_min(t_list *list_a)
{
	int		ret;
	t_node	*node;

	node = list_a->head->next;
	ret = 0;
	while (node->next)
	{
		if (node->data == list_a->min)
			break ;
		ret++;
		node = node->next;
	}
	if (ret >= (list_a->size + 1) / 2)
		ret = (list_a->size - ret) * -1;
	return (ret);
}

int	find_location_mid(t_list *list_a, int num)
{
	int		ret;
	t_node	*node;

	node = list_a->head->next;
	ret = 1;
	while (node->next->next)
	{
		if (num > node->data && num < node->next->data)
			break ;
		ret++;
		node = node->next;
	}
	if (ret >= (list_a->size + 1) / 2)
		ret = (list_a->size - ret) * -1;
	return (ret);
}

int	find_location_max(t_list *list_a)
{
	int		ret;
	t_node	*node;

	node = list_a->head->next;
	ret = 1;
	while (node->next)
	{
		if (node->data == list_a->max)
			break ;
		ret++;
		node = node->next;
	}
	if (ret >= (list_a->size + 1) / 2)
		ret = (list_a->size - ret) * -1;
	return (ret);
}

int	find_location(t_list *list_a, int num)
{
	int	ret;

	if (num < list_a->min)
		ret = find_location_min(list_a);
	else if (num > list_a->max)
		ret = find_location_max(list_a);
	else
		ret = find_location_mid(list_a, num);
	return (ret);
}
