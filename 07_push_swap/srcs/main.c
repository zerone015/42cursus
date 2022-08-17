/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:07:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/17 20:34:20 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	struct_init(t_deque *deque_a, t_deque *deque_b)
{
	deque_init(deque_a);
	deque_init(deque_b);
}

int	main(int argc, char *argv[])
{
	t_deque	deque_a;
	t_deque	deque_b;

	if (argc < 2)
		error("Error");
	struct_init(&deque_a, &deque_b);
	insert_numbers_to_deque(&deque_a, argc, argv);
	sort_ascending(&deque_a, &deque_b);
	return (0);
}
