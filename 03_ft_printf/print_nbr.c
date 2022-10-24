/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:33:34 by yoson             #+#    #+#             */
/*   Updated: 2022/10/24 22:33:24 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static void	set_buf_with_minus(char *buf, int n, int len, t_info *info)
{
	if (info->zero == DISABLE)
	{
		if (set_sign(buf, n, info) == 0)
			buf++;
	}
	ft_memset(buf, '0', info->precision - len);
	buf += info->precision - len;
	ft_itoa(buf, ft_abs(n), 10, "0123456789");
	buf += len;
	ft_memset(buf, ' ', info->width);
}

static void	set_buf(char *buf, int n, int len, t_info *info)
{
	if (info->zero == DISABLE)
	{
		ft_memset(buf, ' ', info->width);
		buf += info->width;
		if (set_sign(buf, n, info) == 0)
			buf++;
		ft_memset(buf, '0', info->precision - len);
		buf += info->precision - len;
		ft_itoa(buf, ft_abs(n), 10, "0123456789");
	}
	else
	{
		if (set_sign(buf, n, info) == 0)
			buf++;
		ft_memset(buf, '0', info->width + info->precision - len);
		buf += info->width + info->precision - len;
		ft_itoa(buf, ft_abs(n), 10, "0123456789");
	}
}

static int	print_with_width(int n, int len, t_info *info)
{
	char	*buf;
	int		size;
	int		print_len;

	size = info->width + find_max(info->precision, len) + sign_exists(info, n);
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

static int	print(int n, int len, t_info *info)
{
	char	buf[11];
	int		i;

	i = 0;
	if (set_sign(buf, n, info) == 0)
		i++;
	if (len)
	{
		ft_itoa(buf + i, ft_abs(n), 10, "0123456789");
		i += len;
	}
	return (write(1, buf, i));
}

int	print_nbr(va_list ap, t_info *info)
{
	int	n;
	int	len;

	if (info->width >= INT_MAX || info->precision >= INT_MAX)
		return (ERROR);
	n = va_arg(ap, int);
	if (info->dot == ENABLE && info->precision == 0 && n == 0)
		len = 0;
	else
		len = find_len(n, 10);
	info->width -= find_max(info->precision, len) + sign_exists(info, n);
	if (info->width > 0 || info->precision - len > 0)
	{
		if (info->precision - len < 0)
			info->precision = len;
		return (print_with_width(n, len, info));
	}
	else
		return (print(n, len, info));
}
