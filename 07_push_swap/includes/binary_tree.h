/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 06:37:47 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 06:48:41 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

typedef struct s_btree
{
	int				data;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

t_btree	*make_btree(void);
int		get_data(t_btree *bt);
void	set_data(t_btree *bt, int data);
t_btree	*get_left_subtree(t_btree *bt);
t_btree	*get_right_subtree(t_btree *bt);
void	change_left_subtree(t_btree *main, t_btree *sub);
void	change_right_subtree(t_btree *main, t_btree *sub);
void	error(char *msg);

#endif
