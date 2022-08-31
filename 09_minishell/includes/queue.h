/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:39:07 by yoson             #+#    #+#             */
/*   Updated: 2022/08/31 19:38:46 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# define TRUE	1
# define FALSE	0

typedef struct s_qnode
{
	int				type;
	char			*str;
	struct s_qnode	*next;
}	t_qnode;

typedef struct s_queue
{
	t_qnode	*front;
	t_qnode	*rear;
}	t_queue;

t_queue	*init_queue(void);
int		queue_is_empty(t_queue *queue);
void	enqueue(t_queue *queue, int type, char *str);
char	*dequeue(t_queue *queue);
int		peek(t_queue *queue);

#endif
