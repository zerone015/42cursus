/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 04:03:45 by yoson             #+#    #+#             */
/*   Updated: 2022/08/17 19:17:06 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number_duplicated(t_deque *deque_a, int num)
{
	t_node	*node;

	node = deque_a->head->next;
	while (node)
	{
		if (node->num == num)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

void	insert_numbers_to_list(t_deque *deque_a, int argc, char *argv[])
{
	int			i;
	int			j;
	char		**numbers;
	int			num;

	i = 1;
	while (i < argc)
	{
		if (*argv[i] == '\0')
			error("Error");
		numbers = ft_split(argv[i++], ' ');
		if (!numbers)
			error("Error");
		j = 0;
		while (numbers[j])
		{
			num = ft_atoi(numbers[j++]);
			if (is_number_duplicated(deque_a, num))
				error("Error");
			add_last(deque_a, num);
		}
		ft_free(numbers);
	}
}
