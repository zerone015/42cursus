/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:23:14 by yoson             #+#    #+#             */
/*   Updated: 2022/11/07 11:39:50 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf_bonus.h"

static int	print(unsigned int n, int len, t_info *info)
{
	char	buf[10];
	int		i;

	i = 0;
	if (info->sharp == ENABLE)
	{
		ft_strncpy(buf, "0X", 2);
		i += 2;
	}
	if (len)
	{
		number_to_string(buf + i, n, 16, "0123456789ABCDEF");
		i += len;
	}
	return (write(1, buf, i));
}

static void	set_buf(char *buf, unsigned int n, int len, t_info *info)
{
	if (info->zero == DISABLE)
	{
		ft_memset(buf, ' ', info->width);
		if (info->sharp == ENABLE)
			ft_strncpy(buf + info->width, "0X", 2);
	}
	else
	{
		if (info->sharp == ENABLE)
		{
			ft_strncpy(buf, "0X", 2);
			ft_memset(buf + 2, '0', info->width);
		}
		else
			ft_memset(buf, '0', info->width);
	}
	buf += info->width + info->sharp * 2;
	if (len)
	{
		ft_memset(buf, '0', info->precision - len);
		buf += info->precision - len;
		number_to_string(buf, n, 16, "0123456789ABCDEF");
		buf += len;
	}
}

static void	set_buf_with_minus(char *buf, unsigned int n, int len, t_info *info)
{
	if (info->sharp == ENABLE)
	{
		ft_strncpy(buf, "0X", 2);
		buf += 2;
	}
	if (len)
	{
		ft_memset(buf, '0', info->precision - len);
		buf += info->precision - len;
		number_to_string(buf, n, 16, "0123456789ABCDEF");
		buf += len;
	}
	ft_memset(buf, ' ', info->width);
	buf += info->width;
}

static int	print_with_width(unsigned int n, int len, t_info *info)
{
	char	*buf;
	int		size;
	int		print_len;

	size = info->width + find_max(info->precision, len) + info->sharp * 2;
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

int	print_hex_upper(va_list ap, t_info *info)
{
	unsigned int	n;
	int				len;

	if (info->width >= INT_MAX || info->precision >= INT_MAX)
		return (ERROR);
	n = va_arg(ap, unsigned int);
	if (n == 0)
		info->sharp = DISABLE;
	if (info->dot == ENABLE && info->precision == 0 && n == 0)
		len = 0;
	else
		len = ft_nbrlen(n, 16);
	info->width -= find_max(info->precision, len) + info->sharp * 2;
	if (info->width > 0 || info->precision - len > 0)
	{
		if (info->precision - len < 0)
			info->precision = len;
		if (info->width < 0)
			info->width = 0;
		return (print_with_width(n, len, info));
	}
	else
		return (print(n, len, info));
}
