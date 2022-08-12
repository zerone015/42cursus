/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 04:03:45 by yoson             #+#    #+#             */
/*   Updated: 2022/08/13 04:04:34 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number_duplicated(t_list *list, int num)
{
	t_node	*node;

	node = list->head->next;
	while (node)
	{
		if (node->num == num)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

void	insert_numbers_to_list(t_list *list, int argc, char *argv[])
{
	int			i;
	int			j;
	char		**numbers;
	long long	num;

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
			if (num == ERROR)
				error("Error");
			if (is_number_duplicated(list, num))
				error("Error");
			l_insert(list, num);
		}
		ft_free(numbers);
	}
}
