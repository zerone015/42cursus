/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:07:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 02:35:57 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	deque_a;

	if (argc < 2)
		return (0);
	deque_init(&deque_a);
	insert_numbers_to_deque(&deque_a, argc, argv);
	preprocess(&deque_a);
	sort_by_ascending(&deque_a);
	return (0);
}
