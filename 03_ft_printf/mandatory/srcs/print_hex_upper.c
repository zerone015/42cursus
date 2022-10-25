/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:23:14 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 21:36:28 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	print(unsigned int n, int len)
{
	char	buf[8];

	ft_ntoa(buf, n, 16, "0123456789ABCDEF");
	return (write(1, buf, len));
}

int	print_hex_upper(va_list ap)
{
	unsigned int	n;
	int				len;

	n = va_arg(ap, unsigned int);
	len = ft_nbrlen(n, 16);
	return (print(n, len));
}
