/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:50:41 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 16:45:17 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	struct_init(t_info info)
{
	info.width = 0;
	info.zero = DISABLE;
	info.space = DISABLE;
	info.plus = DISABLE;
	info.sharp = DISABLE;
	info.minus = DISABLE;
	info.dot = DISABLE;
	info.precision = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_len;

	va_start(ap, format);
	print_len = parse_format(ap, format);
	va_end(ap);
	return (print_len);
}
