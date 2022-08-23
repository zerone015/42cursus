/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 04:03:45 by yoson             #+#    #+#             */
/*   Updated: 2022/08/23 21:16:37 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_numbers_to_deque(t_deque *deque_a, int argc, char *argv[])
{
	int			i;
	char		**numbers;
	int			num;

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
			num = ft_atoi(numbers[i]);
			add_last(deque_a, num);
			i++;
		}
		ft_free(numbers);
	}
}
