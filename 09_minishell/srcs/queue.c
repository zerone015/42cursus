/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:57:10 by yoson             #+#    #+#             */
/*   Updated: 2022/08/31 22:43:06 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = safe_malloc(sizeof(t_queue));
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

int	queue_is_empty(t_queue *queue)
{
	if (queue->front == NULL)
		return (TRUE);
	else
		return (FALSE);
}

void	enqueue(t_queue *queue, int type, char *str)
{
	t_qnode	*new;

	new = safe_malloc(sizeof(t_qnode));
	new->type = type;
	new->str = str;
	new->next = NULL;
	if (queue_is_empty(queue))
	{
		queue->front = new;
		queue->rear = new;
	}
	else
	{
		queue->rear->next = new;
		queue->rear = new;
	}
}

char	*dequeue(t_queue *queue)
{
	t_qnode	*delnode;
	char	*ret;

	if (queue_is_empty(queue))
		return (NULL);
	delnode = queue->front;
	ret = delnode->str;
	queue->front = queue->front->next;
	if (!queue->front)
		queue->rear = NULL;
	free(delnode);
	return (ret);
}

int	peek(t_queue *queue)
{
	if (queue_is_empty(queue))
		return (-1);
	return (queue->front->type);
}
