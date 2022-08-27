/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rarbrrarrb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:09:19 by yoson             #+#    #+#             */
/*   Updated: 2022/08/27 17:09:43 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *list)
{
	add_last(list, remove_first(list));
	ft_putendl_fd("ra", 1);
}

void	rb(t_list *list)
{
	add_last(list, remove_first(list));
	ft_putendl_fd("rb", 1);
}

void	rra(t_list *list)
{
	add_first(list, remove_last(list));
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list *list)
{
	add_first(list, remove_last(list));
	ft_putendl_fd("rrb", 1);
}
