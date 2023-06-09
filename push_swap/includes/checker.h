/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 08:49:57 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 08:53:34 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		execute_instruction(char *line, t_list *list_a, t_list *list_b);
void	c_sa(t_list *list);
void	c_ra(t_list *list);
void	c_rb(t_list *list);
void	c_rra(t_list *list);
void	c_rrb(t_list *list);
void	c_sb(t_list *list);
void	c_pa(t_list *list, int data);
void	c_pb(t_list *list, int data);
void	c_rr(t_list *list_a, t_list *list_b);
void	c_rrr(t_list *list_a, t_list *list_b);

#endif
