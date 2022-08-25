/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:14:43 by yoson             #+#    #+#             */
/*   Updated: 2022/08/26 01:19:17 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(int arr[], int idx1, int idx2)
{
	int	temp;

	temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}
