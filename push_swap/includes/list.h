/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:02:53 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 22:02:02 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
	int		min;
	int		max;
}	t_list;

void	list_init(t_list **list);
void	add_first(t_list *list, int data);
void	add_last(t_list *list, int data);
int		remove_first(t_list *list);
void	list_free(t_list *list);
void	error(char *msg);

#endif
