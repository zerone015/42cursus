/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 05:14:55 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 06:27:44 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

static void	hex_print(unsigned int n)
{
	if (!n)
		return ;
	print(n / 16);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
}

static int	get_nbrlen(unsigned int n)
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

int	print_hex_upper(va_list ap, t_info info)
{
	unsigned int	n;
	int				print_len;
	int				gap;

	if (info->width >= INT_MAX)
		return (ERROR);
	n = va_arg(ap, unsigned int);
	info->width -= get_max(info->precision, get_nbrlen(n)) + info->sharp * 2;
	print_len = 0;
	if (info->minus == DISABLE && info->zero == DISABLE)
		print_len += putnchar(' ', info->width);
	else if (info->minus == DISABLE && info->zero == ENABLE)
		print_len += putnchar('0', info->width);
	gap = info->precision - (get_nbrlen(n) + info->sharp * 2);
	print_len += putnchar('0', gap);
	if (info->sharp == ENABLE)
		print_len += write(1, "0x", 2);
	if (n == 0)
		write(1, "0", 1);
	hex_print(n);
	if (info->minus == ENABLE)
		print_len += putnchar(' ', info->width);
	return (print_len);
}
