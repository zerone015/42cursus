/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:50:41 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 04:14:11 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void	init(t_info info)
{
	info.width = DISABLE;
	info.zero = DISABLE;
	info.space = DISABLE;
	info.plus = DISABLE;
	info.sharp = DISABLE;
	info.minus = DISABLE;
	info.precision = DISABLE;
}

static int	parse_format(va_list ap, const char *format)
{
	t_info	info;
	int		print_len;
	int		temp;

	print_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			init(&info);
			format++;
			parse_flag(&info, &format);
			parse_width(&info, &format);
			parse_precision(&info, &format);
			temp = parse_type(&info, ap, *format);
			if (temp == ERROR)
				return (ERROR);
			print_len += temp;
		}
		else
			print_len += write(1, format, 1);
		format++;
	}
	return (print_len);
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
