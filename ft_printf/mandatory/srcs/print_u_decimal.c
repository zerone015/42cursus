/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:33:34 by yoson             #+#    #+#             */
/*   Updated: 2022/11/07 11:32:48 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	print(unsigned int n, int len)
{
	char	buf[10];

	number_to_string(buf, n, 10, "0123456789");
	return (write(1, buf, len));
}

int	print_u_decimal(va_list ap)
{
	unsigned int	n;
	int				len;

	n = va_arg(ap, int);
	len = ft_nbrlen(n, 10);
	return (print(n, len));
}
