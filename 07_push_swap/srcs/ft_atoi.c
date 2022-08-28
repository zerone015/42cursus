/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:38:02 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 21:16:32 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	check_over_range(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		error("Error");
	return (num);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	num;
	int			i;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
		if (!ft_isdigit(*str))
			error("Error");
	}
	while (*str == '0')
		str++;
	i = -1;
	while (str[++i] != '\0' && i <= INT_MAX_LEN + 1)
	{
		if (!ft_isdigit(str[i]))
			error("Error");
		num = num * 10 + str[i] - '0';
	}
	return (check_over_range(num * sign));
}
