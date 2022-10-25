/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:00:42 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 20:56:43 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_bonus.h"

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

void	ft_strncpy(char *dest, const char *src, size_t n)
{
	while (*src && n)
	{
		*dest++ = *src++;
		n--;
	}
}
