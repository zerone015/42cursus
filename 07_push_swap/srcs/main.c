/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:07:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/19 05:05:04 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	deque_a;

	if (argc < 2)
		error("Error");
	deque_init(&deque_a);
	insert_numbers_to_deque(&deque_a, argc, argv);
	sort_ascending(&deque_a);
	return (0);
}
