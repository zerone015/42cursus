/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rebalance.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 06:26:15 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 06:45:53 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_REBALANCE_H
# define AVL_REBALANCE_H

# include "binary_tree.h"

int		get_height(t_btree *bst);
int		get_height_diff(t_btree *bst);
t_btree	*rebalance(t_btree **bst);
t_btree	*rotate_ll(t_btree *bst);
t_btree	*rotate_rr(t_btree *bst);
t_btree	*rotate_rl(t_btree *bst);
t_btree	*rotate_lr(t_btree *bst);

#endif
