/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:23:14 by yoson             #+#    #+#             */
/*   Updated: 2022/07/22 11:40:32 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

static int	print(char hex_arr[], unsigned int n, int len)
{
	int	print_len;

	if (len == 0)
		return (0);
	hex_arr[len--] = '\0';
	if (n == 0)
		hex_arr[len] = '0';
	while (n > 0)
	{
		hex_arr[len--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	print_len = write(1, hex_arr, ft_strlen(hex_arr));
	return (print_len);
}

static int	get_hexlen(unsigned int n, t_info *info)
{
	int	len;

	if (info->dot == ENABLE && info->precision == 0 && n == 0)
		return (0);
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

int	print_hex_lower(va_list ap, t_info *info)
{
	char			hex_arr[9];
	unsigned int	n;
	int				print_len;
	int				hex_len;

	if (info->width >= INT_MAX)
		return (ERROR);
	n = va_arg(ap, unsigned int);
	if (n == 0)
		info->sharp = 0;
	hex_len = get_hexlen(n, info);
	info->width -= get_max(info->precision, hex_len) + info->sharp * 2;
	print_len = 0;
	if (info->minus == DISABLE && info->zero == DISABLE)
		print_len += putnchar(' ', info->width);
	if (info->sharp == ENABLE && n > 0)
		print_len += write(1, "0x", 2);
	if (info->minus == DISABLE && info->zero == ENABLE)
		print_len += putnchar('0', info->width);
	print_len += putnchar('0', info->precision - hex_len);
	print_len += print(hex_arr, n, hex_len);
	if (info->minus == ENABLE)
		print_len += putnchar(' ', info->width);
	return (print_len);
}
