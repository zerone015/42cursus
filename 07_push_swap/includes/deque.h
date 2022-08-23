/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:02:53 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 00:35:16 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
	int		num_cnt;
}	t_deque;

void	deque_init(t_deque *deque);
void	add_first(t_deque *deque, int data);
void	add_last(t_deque *deque, int data);
int		remove_first(t_deque *deque);
int		remove_last(t_deque *deque);

#endif
