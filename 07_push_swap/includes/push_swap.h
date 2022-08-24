/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:08:08 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 18:08:55 by yoson            ###   ########.fr       */
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
void	sort_by_ascending(t_list *list_a);
void	a_to_b(t_list *list_a, t_list *list_b, int ra_cnt);
void	b_to_a(t_list *list_a, t_list *list_b, int pb_cnt);
void	swap(t_list *list, char *str);
void	push(t_list *list, int data, char *str);
void	rotate(t_list *list, char *str);
void	reverse_rotate(t_list *list, char *str);
void	quick_sort(int arr[], int left, int right);
void	error(char *msg);
int		binary_search(int arr[], int len, int target);
void	ft_free(char *strs[]);

#endif
