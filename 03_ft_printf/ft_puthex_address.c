/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:51:26 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 02:02:14 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	print(uintptr_t address, int print_len)
{
	if (!address)
		return (0);
	print_len = print(address / 16, print_len);
	write(1, &"0123456789abcdef"[address % 16], 1);
	print_len++;
	return (print_len);
}

int	ft_puthex_address(uintptr_t address)
{
	int	print_len;

	print_len = write(1, "0x", 2);
	if (!address)
	{
		print_len += write(1, "0", 1);
		return (print_len);
	}
	print_len += print(address, 0);
	return (print_len);
}
