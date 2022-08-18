/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 04:03:45 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 07:17:10 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number_duplicated(t_btree *bst, int num)
{
	if (bst_insert(&bst, num) == NULL)
		return (TRUE);
	return (FALSE);
}

void	insert_numbers_to_deque(t_deque *deque_a, int argc, char *argv[])
{
	t_btree		*bst;
	char		**numbers;
	int			i;
	int			j;
	int			num;

	bst_init(&bst);
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
			if (is_number_duplicated(bst, num))
				error("Error");
			add_last(deque_a, num);
		}
		ft_free(numbers);
	}
}
