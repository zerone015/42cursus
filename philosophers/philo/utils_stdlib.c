/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stdlib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:28:50 by yoson             #+#    #+#             */
/*   Updated: 2022/09/13 18:21:38 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	i = -1;
	while (str[++i] && i < 11)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		num *= 10;
		num += str[i] - '0';
	}
	if (num > INT_MAX || !num)
		return (-1);
	return (num);
}

void	*safe_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		return ((void *)print_err("Malloc failed"));
	return (p);
}
