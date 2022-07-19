/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_hexprint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:34:37 by yoson             #+#    #+#             */
/*   Updated: 2022/07/19 22:34:38 by yoson            ###   ########.fr       */
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

int	ft_address_hexprint(uintptr_t address)
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
