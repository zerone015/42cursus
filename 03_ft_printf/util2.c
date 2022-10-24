/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:50:10 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 03:44:57 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs(int n)
{
	long long	ret;

	ret = n;
	if (n < 0)
		ret *= -1;
	return (ret);
}

int	sign_exists(t_info *info, int n)
{
	if (info->space == ENABLE && n >= 0)
		return (TRUE);
	if (info->plus == ENABLE || n < 0)
		return (TRUE);
	return (FALSE);
}

int	set_sign(char *buf, int n, t_info *info)
{
	if (info->plus == ENABLE && n >= 0)
		*buf = '+';
	else if (info->space == ENABLE && n >= 0)
		*buf = ' ';
	else if (n < 0)
		*buf = '-';
	else
		return (ERROR);
	return (0);
}

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	find_len(size_t	n, int radix)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n /= radix;
	}
	return (len);
}