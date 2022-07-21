/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 05:14:55 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 15:49:46 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

static int	print(char hex_arr[], unsigned int n, int len)
{
	int	print_len;

	hex_arr[len--] = '\0';
	if (n == 0)
		hex_arr[len] = '0';
	while (n > 0)
	{
		hex_arr[len--] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	print_len = write(1, hex_arr, ft_strlen(hex_arr));
	return (print_len);
}

static int	get_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	print_hex_upper(va_list ap, t_info *info)
{
	char		hex_arr[9];
	unsigned int	n;
	int				print_len;
	int				gap;

	if (info->width >= INT_MAX)
		return (ERROR);
	n = va_arg(ap, unsigned int);
	info->width -= get_max(info->precision, get_hexlen(n)) + info->sharp * 2;
	print_len = 0;
	if ((info->minus == DISABLE && info->zero == DISABLE) || (info->minus == DISABLE && info->dot == ENABLE))
		print_len += putnchar(' ', info->width);
	else if (info->minus == DISABLE && info->zero == ENABLE)
		print_len += putnchar('0', info->width);
	gap = info->precision - (get_hexlen(n) + info->sharp * 2);
	print_len += putnchar('0', gap);
	if (info->sharp == ENABLE)
		print_len += write(1, "0x", 2);
	print_len += print(hex_arr, n, get_hexlen(n));
	if (info->minus == ENABLE)
		print_len += putnchar(' ', info->width);
	return (print_len);
}
