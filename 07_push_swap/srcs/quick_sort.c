/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:58:19 by yoson             #+#    #+#             */
/*   Updated: 2022/08/23 23:18:34 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int arr[], int idx1, int idx2)
{
	int	temp;

	temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

static int	median_of_three(int arr[], int left, int right)
{
	int	idx[3];

	idx[0] = left;
	idx[1] = (left + right) / 2;
	idx[2] = right;
	if (arr[idx[0]] > arr[idx[1]])
		swap(idx, 0, 1);
	if (arr[idx[1]] > arr[idx[2]])
		swap(idx, 1, 2);
	if (arr[idx[0]] > arr[idx[1]])
		swap(idx, 0, 1);
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
	swap(arr, left, p_idx);
	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
			low++;
		while (pivot < arr[high] && high >= (left + 1))
			high--;
		if (low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
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
