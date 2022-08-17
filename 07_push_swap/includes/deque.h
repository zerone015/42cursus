/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:02:53 by yoson             #+#    #+#             */
/*   Updated: 2022/08/17 19:04:01 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

typedef struct s_node
{
	int				num;
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
void	add_first(t_deque *deque, int num);
void	add_last(t_deque *deque, int num);
int		remove_first(t_deque *deque);
int		remove_last(t_deque *deque);

#endif
