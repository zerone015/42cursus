/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:41:00 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 06:23:01 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

static void	hex_print(uintptr_t address)
{
	if (!address)
		return ;
	print(address / 16);
	write(1, &"0123456789abcdef"[address % 16], 1);
}

static int	get_hexlen(uintptr_t address)
{
	int	len;

	len = 0;
	if (address == 0)
		len++;
	while (address)
	{
		len++;
		address /= 16;
	}
	return (len);
}

int	print_hex_address(va_list ap, t_info info)
{
	uintptr_t	address;
	int			print_len;

	if (info->width >= INT_MAX)
		return (ERROR);
	address = va_arg(ap, uintptr_t);
	info->width -= get_hexlen(address) + 2;
	print_len = 0;
	if (info->minus == DISABLE)
		print_len += putnchar(' ', info->width);
	print_len += write(1, "0x", 2);
	if (address == 0)
		write(1, "0", 1);
	hex_print(address);
	print_len += get_hexlen(address);
	if (info->minus == ENABLE)
		print_len += putnchar(' ', info->width);
	return (print_len);
}
