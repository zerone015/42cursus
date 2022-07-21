/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:41:00 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 17:09:35 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

static int	print(char hex_arr[], uintptr_t address, int len)
{
	int	print_len;

	hex_arr[len--] = '\0';
	if (address == 0)
		hex_arr[len] = '0';
	while (address > 0)
	{
		hex_arr[len--] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	print_len = write(1, hex_arr, ft_strlen(hex_arr));
	return (print_len);
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

int	print_hex_address(va_list ap, t_info *info)
{
	char		hex_arr[19];
	uintptr_t	address;
	int			hex_len;
	int			print_len;

	if (info->width >= INT_MAX)
		return (ERROR);
	address = va_arg(ap, uintptr_t);
	hex_len = get_hexlen(address);
	info->width -= hex_len + 2;
	print_len = 0;
	if (info->minus == DISABLE)
		print_len += putnchar(' ', info->width);
	print_len += write(1, "0x", 2);
	print_len += print(hex_arr, address, hex_len);
	if (info->minus == ENABLE)
		print_len += putnchar(' ', info->width);
	return (print_len);
}
