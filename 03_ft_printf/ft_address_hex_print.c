/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:30:46 by yoson             #+#    #+#             */
/*   Updated: 2022/07/19 21:33:14 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	recursive_print(uintptr_t address, int len)
{
	if (!address)
		return (0);
	len = recursive_print(address / 16, len);
	write(1, &"0123456789abcdef"[address % 16], 1);
	len++;
	return (len);
}

int	ft_address_hex_print(uintptr_t address)
{
	int	len;

	len = write(1, "0x", 2);
	if (!address)
	{
		len += write(1, "0", 1);
		return (len);
	}
	len += recursive_print(address, 0);
	return (len);
}
