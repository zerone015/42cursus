/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:39:41 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 03:43:09 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static int	print_with_width(t_info *info, char c)
{
	char	*buf;
	int		print_len;

	buf = (char *)malloc(info->width);
	if (!buf)
		return (ERROR);
	if (info->minus == DISABLE)
	{
		ft_memset(buf, ' ', info->width - 1);
		buf[info->width - 1] = c;
	}
	else
	{
		buf[0] = c;
		ft_memset(buf + 1, ' ', info->width - 1);
	}
	print_len = write(1, buf, info->width);
	free(buf);
	return (print_len);
}

int	print_char(va_list ap, t_info *info)
{
	char	c;

	if (info->width >= INT_MAX)
		return (ERROR);
	c = va_arg(ap, int);
	if (info->width > 1)
		return (print_with_width(info, c));
	else
		return (write(1, &c, 1));
}
