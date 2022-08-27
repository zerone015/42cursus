/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:07:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 06:51:25 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_numbers_to_list(t_list *list_a, int argc, char *argv[])
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
			add_last(list_a, num);
			i++;
		}
		ft_free(numbers);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*list_a;

	if (argc < 2)
		return (1);
	list_init(&list_a);
	insert_numbers_to_list(list_a, argc, argv);
	preprocess(list_a);
	sort_by_ascending(list_a);
	return (0);
}
