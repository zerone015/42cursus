/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:58:19 by yoson             #+#    #+#             */
/*   Updated: 2022/08/26 01:12:31 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	median_of_three(int arr[], int left, int right)
{
	int	idx[3];

	idx[0] = left;
	idx[1] = (left + right) / 2;
	idx[2] = right;
	if (arr[idx[0]] > arr[idx[1]])
		ft_swap(idx, 0, 1);
	if (arr[idx[1]] > arr[idx[2]])
		ft_swap(idx, 1, 2);
	if (arr[idx[0]] > arr[idx[1]])
		ft_swap(idx, 0, 1);
	return (idx[1]);
}

static int	partition(int arr[], int left, int right)
{
	int	p_idx;
	int	pivot;
	int	low;
	int	high;

	p_idx = median_of_three(arr, left, right);
	pivot = arr[p_idx];
	low = left + 1;
	high = right;
	ft_swap(arr, left, p_idx);
	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
			low++;
		while (pivot < arr[high] && high >= (left + 1))
			high--;
		if (low <= high)
			ft_swap(arr, low, high);
	}
	ft_swap(arr, left, high);
	return (high);
}

void	quick_sort(int arr[], int left, int right)
{
	int	pivot;

	if (left <= right)
	{
		pivot = partition(arr, left, right);
		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot + 1, right);
	}
}
