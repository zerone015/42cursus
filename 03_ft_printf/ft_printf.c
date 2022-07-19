/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:50:41 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 00:50:02 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	parse_type(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_puthex_address(va_arg(ap, uintptr_t)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthex_tolower(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (ft_puthex_toupper(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

static int	parse_format(const char *format, va_list ap)
{
	int	result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
			result += parse_type(*(++format), ap);
		else
			result += write(1, format, 1);
		++format;
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = parse_format(format, ap);
	va_end(ap);
	return (result);
}
