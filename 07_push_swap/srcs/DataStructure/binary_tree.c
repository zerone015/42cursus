/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 06:36:07 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 06:44:40 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "binary_tree.h"

t_btree	*make_btree(void)
{
	t_btree	*bt;

	bt = (t_btree *) malloc(sizeof(t_btree));
	if (!bt)
		error("Error");
	bt->left = NULL;
	bt->right = NULL;
	return (bt);
}

int	get_data(t_btree *bt)
{
	return (bt->data);
}

void	set_data(t_btree *bt, int data)
{
	bt->data = data;
}
