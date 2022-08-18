/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 06:36:42 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 06:37:03 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

t_btree	*get_left_subtree(t_btree *bt)
{
	return (bt->left);
}

t_btree	*get_right_subtree(t_btree *bt)
{
	return (bt->right);
}

void	change_left_subtree(t_btree *main, t_btree *sub)
{
	main->left = sub;
}

void	change_right_subtree(t_btree *main, t_btree *sub)
{
	main->right = sub;
}
