/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:07:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/13 04:05:18 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	struct_init(t_list *list, t_stack *stack)
{
	list_init(&list);
	stack_init(&stack);
}

int	main(int argc, char *argv[])
{
	t_list	list;
	t_stack	stack;

	if (argc < 2)
		error("Error");
	struct_init(&list, &stack);
	insert_numbers_to_list(&list, argc, argv);
	sort_ascending(&stack_a, &stack_b);
	return (0);
}
