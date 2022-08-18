/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 04:03:45 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 08:24:40 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number_duplicated(t_btree *bst, int num)
{
	if (bst_insert(&bst, num) == ERROR)
		return (TRUE);
	return (FALSE);
}

void	insert_numbers_to_deque(t_deque *deque_a, int argc, char *argv[])
{
	int			i;
	t_btree		*bst;
	char		**numbers;
	int			num;

	bst_init(&bst);
	while (--argc)
	{
		if (**(++argv) == '\0')
			error("Error");
		numbers = ft_split(*argv, ' ');
		if (!numbers)
			error("Error");
		i = 0;
		while (numbers[i])
		{
			num = ft_atoi(numbers[i++]);
			if (is_number_duplicated(bst, num))
				error("Error");
			add_last(deque_a, num);
		}
		ft_free(numbers);
	}
	tree_free(bst);
}
