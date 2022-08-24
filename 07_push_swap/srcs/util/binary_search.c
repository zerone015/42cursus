/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:36:56 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 17:19:35 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	binary_search(int arr[], int len, int target)
{
	int	first;
	int	last;
	int	mid;

	first = 0;
	last = len - 1;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (target == arr[mid])
		{
			return (mid);
		}
		else
		{
			if (target < arr[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return (-1);
}
