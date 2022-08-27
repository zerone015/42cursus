/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:08:08 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 00:23:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE		1
# define FALSE		0

# include "list.h"
# include "../libft/libft.h"

void	insert_numbers_to_list(t_list *list_a, int argc, char *argv[]);
void	preprocess(t_list *list_a);
void	sa(t_list *list);
void	pa(t_list *list, int data);
void	pb(t_list *list, int data);
void	ra(t_list *list);
void	rb(t_list *list);
void	rra(t_list *list);
void	rrb(t_list *list);
void	rr(t_list *list_a, t_list *list_b);
void	rrr(t_list *list_a, t_list *list_b);
void	sort_by_ascending(t_list *list_a);
int		find_location(t_list *list_a, int num);
void	b_to_a(t_list *list_a, t_list *list_b, t_node *node_b);
void	division(t_list *list_a, t_list *list_b);
void	three_division(t_list *list_a, t_list *list_b, int size);
void	rotate(t_list *list_a, t_list *list_b, int idx_a, int idx_b);
void	last_sort(t_list *list_a);
int		abs_sum(int num1, int num2);
void	sort_three(t_list *list);
int		get_min(t_node *node);
int		get_max(t_node *node);
int		find_location_min(t_list *list_a);
int		find_location_mid(t_list *list_a, int num);
int		find_location_max(t_list *list_a);
void	quick_sort(int arr[], int left, int right);
int		binary_search(int arr[], int len, int target);

#endif
