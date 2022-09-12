/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stdlib_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:28:50 by yoson             #+#    #+#             */
/*   Updated: 2022/09/13 00:07:54 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "philo_bonus.h"

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
			error("Invalid arguments");
		num *= 10;
		num += str[i] - '0';
	}
	if (num > INT_MAX)
		error("Value too large for defined data type");
	return (num);
}

void	error(char *err_msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(err_msg, 2);
	exit(1);
}

void	*safe_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		error("Out of memory");
	return (p);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = safe_malloc(count * size);
	return (ft_memset(p, 0, count * size));
}
