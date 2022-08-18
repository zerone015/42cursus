/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rebalance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 06:23:31 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 06:47:31 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl_rebalance.h"

int	get_height(t_btree *bst)
{
	int	left_height;
	int	right_height;

	if (bst == NULL)
		return (0);
	left_height = get_height(get_left_subtree(bst));
	right_height = get_height(get_right_subtree(bst));
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

int	get_height_diff(t_btree *bst)
{
	int	left_height;
	int	right_height;

	if (bst == NULL)
		return (0);
	left_height = get_height(get_left_subtree(bst));
	right_height = get_height(get_right_subtree(bst));
	return (left_height - right_height);
}

t_btree	*rebalance(t_btree **bst)
{
	int	diff;

	diff = get_height_diff(*bst);
	if (diff > 1)
	{
		if (get_height_diff(get_left_subtree(*bst)) > 0)
			*bst = rotate_ll(*bst);
		else
			*bst = rotate_lr(*bst);
	}
	else if (diff < -1)
	{
		if (get_height_diff(get_right_subtree(*bst)) < 0)
			*bst = rotate_rr(*bst);
		else
			*bst = rotate_rl(*bst);
	}
	return (*bst);
}
