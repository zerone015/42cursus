/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:50:41 by yoson             #+#    #+#             */
/*   Updated: 2022/07/19 21:57:25 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	print_arg(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_address_hex_print(va_arg(ap, uintptr_t)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_hex_print_tolower(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (ft_hex_print_toupper(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
}

static int	parse_format(const char *format, va_list ap)
{
	int	result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
			result += print_arg(*(++format), ap);
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
	result = parse_format(ap, fortmat);
	return (result);
}
