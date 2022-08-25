/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:08:08 by yoson             #+#    #+#             */
/*   Updated: 2022/08/26 01:11:57 by yoson            ###   ########.fr       */
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
void	sort_by_ascending(t_list *list_a, t_list *list_b);
void	swap(t_list *list, char *str);
void	push(t_list *list, int data, char *str);
void	rotate(t_list *list, char *str);
void	reverse_rotate(t_list *list, char *str);
void	quick_sort(int arr[], int left, int right);
int		binary_search(int arr[], int len, int target);

#endif
