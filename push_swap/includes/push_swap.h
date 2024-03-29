/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:08:08 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 22:45:42 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE			1
# define FALSE			0
# define INT_MAX_LEN	10

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
void	sort(t_list *list_a);
void	sort_three(t_list *list);
int		is_already_sorted(t_list *list_a);
void	three_division(t_list *list_a, t_list *list_b, int size);
void	b_to_a(t_list *list_a, t_list *list_b, t_node *node_b);
int		find_location(t_list *list_a, int num);
int		find_location_min(t_list *list_a);
int		find_location_mid(t_list *list_a, int num);
int		find_location_max(t_list *list_a);
void	rotate(t_list *list_a, t_list *list_b, int idx_a, int idx_b);
void	update_min_max(t_list *list_a);
void	last_sort(t_list *list_a);
int		abs_sum(int num1, int num2);
void	quick_sort(int arr[], int left, int right);
int		binary_search(int arr[], int len, int target);
int		ft_atoi(const char *str);

#endif
