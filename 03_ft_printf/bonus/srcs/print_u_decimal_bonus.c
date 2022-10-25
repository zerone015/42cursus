/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_decimal_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:33:34 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 20:05:40 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf_bonus.h"

static int	print(unsigned int n, int len)
{
	char	buf[10];

	if (len)
	{
		ft_ntoa(buf, n, 10, "0123456789");
	}
	return (write(1, buf, len));
}

static void	set_buf_with_minus(char *buf, unsigned int n, int len, t_info *info)
{
	if (len)
	{
		ft_memset(buf, '0', info->precision - len);
		buf += info->precision - len;
		ft_ntoa(buf, n, 10, "0123456789");
		buf += len;
	}
	ft_memset(buf, ' ', info->width);
}

static void	set_buf(char *buf, unsigned int n, int len, t_info *info)
{
	if (info->zero == DISABLE)
	{
		ft_memset(buf, ' ', info->width);
		buf += info->width;
	}
	else
	{
		ft_memset(buf, '0', info->width);
		buf += info->width;
	}
	if (len)
	{
		ft_memset(buf, '0', info->precision - len);
		buf += info->precision - len;
		ft_ntoa(buf, n, 10, "0123456789");
	}
}

static int	print_with_width(unsigned int n, int len, t_info *info)
{
	char	*buf;
	int		size;
	int		print_len;

	size = info->width + find_max(info->precision, len);
	buf = malloc(size);
	if (!buf)
		return (ERROR);
	if (info->minus == DISABLE)
		set_buf(buf, n, len, info);
	else
		set_buf_with_minus(buf, n, len, info);
	print_len = write(1, buf, size);
	free(buf);
	return (print_len);
}

int	print_u_decimal(va_list ap, t_info *info)
{
	unsigned int	n;
	int				len;

	if (info->width >= INT_MAX || info->precision >= INT_MAX)
		return (ERROR);
	n = va_arg(ap, int);
	if (info->dot == ENABLE && info->precision == 0 && n == 0)
		len = 0;
	else
		len = ft_nbrlen(ft_abs(n), 10);
	info->width -= find_max(info->precision, len);
	if (info->width > 0 || info->precision - len > 0)
	{
		if (info->precision - len < 0)
			info->precision = len;
		if (info->width < 0)
			info->width = 0;
		return (print_with_width(n, len, info));
	}
	else
		return (print(n, len));
}
