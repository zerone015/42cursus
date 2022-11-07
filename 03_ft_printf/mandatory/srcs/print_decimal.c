/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:33:34 by yoson             #+#    #+#             */
/*   Updated: 2022/11/07 11:32:14 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	print(int n, int len)
{
	char	buf[11];
	int		i;

	i = 0;
	if (n < 0)
	{
		buf[0] = '-';
		i++;
	}
	number_to_string(buf + i, ft_abs(n), 10, "0123456789");
	return (write(1, buf, i + len));
}

int	print_decimal(va_list ap)
{
	int	n;
	int	len;

	n = va_arg(ap, int);
	len = ft_nbrlen(ft_abs(n), 10);
	return (print(n, len));
}
