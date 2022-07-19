/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:51:26 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 03:13:23 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	zero_print(void)
{
	return (write(1, "0x0", 3));
}

static void	print(uintptr_t address)
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
	while (address)
	{
		len++;
		address /= 16;
	}
	return (len);
}

int	ft_puthex_address(uintptr_t address)
{
	int	print_len;

	if (!address)
		return (zero_print());
	print_len = write(1, "0x", 2);
	print(address);
	print_len += get_hexlen(address);
	return (print_len);
}
