/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:07:17 by yoson             #+#    #+#             */
/*   Updated: 2022/08/26 01:05:19 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	list_a;
	t_list	list_b;

	if (argc < 2)
		return (1);
	list_init(&list_a);
	insert_numbers_to_list(&list_a, argc, argv);
	preprocess(&list_a);
	list_init(&list_b);
	sort_by_ascending(&list_a, &list_b);
	return (0);
}
