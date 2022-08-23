/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:36:56 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 01:21:36 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	interpolation_search(int arr[], int first, int last, int target)
{
	int	idx;

	if (arr[first] > target || arr[last] < target)
		return (-1);
	idx = ((double)(target - arr[first]) / (arr[last] - arr[first]) * \
			(last - first)) + first;
	if (arr[idx] == target)
		return (idx);
	else if (target < arr[idx])
		return (interpolation_search(arr, first, idx - 1, target));
	else
		return (interpolation_search(arr, idx + 1, last, target));
}
