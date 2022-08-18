/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rebalance2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 06:22:45 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 07:04:12 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl_rebalance.h"

t_btree	*rotate_ll(t_btree *bst)
{
	t_btree	*parent;
	t_btree	*child;

	parent = bst;
	child = get_left_subtree(parent);
	change_left_subtree(parent, get_right_subtree(child));
	change_right_subtree(child, parent);
	return (child);
}

t_btree	*rotate_rr(t_btree *bst)
{
	t_btree	*parent;
	t_btree	*child;

	parent = bst;
	child = get_right_subtree(parent);
	change_right_subtree(parent, get_left_subtree(child));
	change_left_subtree(child, parent);
	return (child);
}

t_btree	*rotate_rl(t_btree *bst)
{
	t_btree	*parent;
	t_btree	*child;

	parent = bst;
	child = get_right_subtree(parent);
	change_right_subtree(parent, rotate_ll(child));
	return (rotate_rr(parent));
}

t_btree	*rotate_lr(t_btree *bst)
{
	t_btree	*parent;
	t_btree	*child;

	parent = bst;
	child = get_left_subtree(parent);
	change_left_subtree(parent, rotate_rr(child));
	return (rotate_ll(parent));
}
