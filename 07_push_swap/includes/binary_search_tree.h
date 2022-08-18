/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 05:44:42 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 08:03:00 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_H
# define BINARY_SEARCH_TREE_H

# define ERROR -1

# include "binary_tree.h"

void	bst_init(t_btree **bst);
int		bst_insert(t_btree **bst, int data);

#endif
