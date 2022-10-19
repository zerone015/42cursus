/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:39:41 by yoson             #+#    #+#             */
/*   Updated: 2022/10/19 17:49:38 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static int	buffer_print(int width, int minus_flag, char c)
{
	char	*buf;
	int		print_len;

	buf = (char *)malloc(width + 1);
	if (!buf)
		return (ERROR);
	if (minus_flag == DISABLE)
	{
		ft_memset(buf, ' ', width - 1);
		buf[width - 1] = c;
	}
	else
	{
		buf[0] = c;
		ft_memset(buf + 1, ' ', width - 1);
	}
		buf[width] = '\0';
	print_len = write(1, buf, width);
	free(buf);
	return (print_len);
}

int	print_char(va_list ap, t_info *info)
{
	char	c;

	if (info->width >= INT_MAX)
		return (ERROR);
	c = va_arg(ap, int);
	if (info->width)
		return (buffer_print(info->width, info->minus, c));
	else
		return (write(1, &c, 1));
}
