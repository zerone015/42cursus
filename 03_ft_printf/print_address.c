/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:41:00 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 04:24:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static int	print_with_width(uintptr_t n, int len, t_info *info)
{
	char	*buf;
	int		print_len;

	buf = malloc(info->width);
	if (!buf)
		return (ERROR);
	if (info->minus == DISABLE)
	{
		ft_memset(buf, ' ', info->width - len - 2);
		ft_strncpy(buf + info->width - len - 2, "0x", 2);
		ft_itoa(buf + info->width - len, n, 16, "0123456789abcdef");
	}
	else
	{
		ft_strncpy(buf, "0x", 2);
		ft_itoa(buf + 2, n, 16, "0123456789abcdef");
		ft_memset(buf + len + 2, ' ', info->width - len - 2);
	}
	print_len = write(1, buf, info->width);
	free(buf);
	return (print_len);
}

static int	print(uintptr_t n, int len)
{
	char	buf[19];

	ft_strncpy(buf, "0x", 2);
	ft_itoa(buf + 2, n, 16, "0123456789abcdef");
	return (write(1, buf, len + 2));
}

int	print_address(va_list ap, t_info *info)
{
	uintptr_t	n;
	int			len;

	if (info->width >= INT_MAX)
		return (ERROR);
	n = va_arg(ap, uintptr_t);
	len = find_len(n, 16);
	if (info->width > len + 2)
		return (print_with_width(n, len, info));
	else
		return (print(n, len));
}
