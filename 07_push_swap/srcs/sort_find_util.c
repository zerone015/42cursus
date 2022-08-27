/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_find_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:29:35 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 00:56:34 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_node *node)
{
	int	ret;

	ret = node->data;
	while (node->next)
	{
		if (ret > node->data)
			ret = node->data;
		node = node->next;
	}
	return (ret);
}

int	get_max(t_node *node)
{
	int	ret;

	ret = node->data;
	while (node->next)
	{
		if (ret < node->data)
			ret = node->data;
		node = node->next;
	}
	return (ret);
}

int	find_location_min(t_list *list_a)
{
	int		ret;
	int		idx;
	t_node	*node;

	node = list_a->head->next;
	idx = get_min(node);
	ret = 0;
	while (node->next)
	{
		if (node->data == idx)
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
	int		idx;
	t_node	*node;

	node = list_a->head->next;
	idx = get_max(node);
	ret = 1;
	while (node->next)
	{
		if (node->data == idx)
			break ;
		ret++;
		node = node->next;
	}
	if (ret >= (list_a->size + 1) / 2)
		ret = (list_a->size - ret) * -1;
	return (ret);
}
