/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 05:44:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 07:28:37 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "binary_tree.h"
#include "binary_search_tree.h"
#include "avl_rebalance.h"

void	bst_init(t_btree **bst)
{
	*bst = NULL;
}

t_btree	*bst_insert(t_btree **bst, int data)
{
	if (*bst == NULL)
	{
		*bst = make_btree();
		set_data(*bst, data);
	}
	else if (data < get_data(*bst))
	{
		bst_insert(&((*bst)->left), data);
		*bst = rebalance(bst);
	}
	else if (data > get_data(*bst))
	{
		bst_insert(&((*bst)->right), data);
		*bst = rebalance(bst);
	}
	else
	{
		return (NULL);
	}
	return (*bst);
}
