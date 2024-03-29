/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:12:54 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 20:04:59 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf_bonus.h"

static int	print_with_width(t_info *info)
{
	char	*buf;
	int		print_len;

	buf = (char *)malloc(info->width);
	if (!buf)
		return (ERROR);
	if (info->minus == DISABLE)
	{
		if (info->zero == DISABLE)
			ft_memset(buf, ' ', info->width - 1);
		else
			ft_memset(buf, '0', info->width - 1);
		buf[info->width - 1] = '%';
	}
	else
	{
		buf[0] = '%';
		ft_memset(buf + 1, ' ', info->width - 1);
	}
	print_len = write(1, buf, info->width);
	free(buf);
	return (print_len);
}

int	print_percent(va_list ap, t_info *info)
{
	(void)ap;
	if (info->width >= INT_MAX)
		return (ERROR);
	if (info->width)
		return (print_with_width(info));
	else
		return (write(1, "%", 1));
}
