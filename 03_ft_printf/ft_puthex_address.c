/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:51:26 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 00:54:01 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	print(uintptr_t address, int len)
{
	if (!address)
		return (0);
	len = print(address / 16, len);
	write(1, &"0123456789abcdef"[address % 16], 1);
	len++;
	return (len);
}

int	ft_puthex_address(uintptr_t address)
{
	int	len;

	len = write(1, "0x", 2);
	if (!address)
	{
		len += write(1, "0", 1);
		return (len);
	}
	len += print(address, 0);
	return (len);
}
