/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:36:56 by yoson             #+#    #+#             */
/*   Updated: 2022/08/23 22:59:38 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	interpolation_search(int arr[], int first, int last, int target)
{
	int	mid;

	if (arr[first] > target || arr[last] < target)
		return (-1);
	mid = ((double)(target - arr[first]) / (arr[last] - arr[first]) * \
			(last - first)) + first;
	if (arr[mid] == target)
		return (mid);
	else if (target < arr[mid])
		return (interpolation_search(arr, first, mid - 1, target));
	else
		return (interpolation_search(arr, mid + 1, last, target));
}
