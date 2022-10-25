/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:41:00 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 21:45:05 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	print(uintptr_t n, int len)
{
	char	buf[19];

	buf[0] = '0';
	buf[1] = 'x';
	ft_ntoa(buf + 2, n, 16, "0123456789abcdef");
	return (write(1, buf, len + 2));
}

int	print_address(va_list ap)
{
	uintptr_t	n;
	int			len;

	n = va_arg(ap, uintptr_t);
	len = ft_nbrlen(n, 16);
	return (print(n, len));
}
