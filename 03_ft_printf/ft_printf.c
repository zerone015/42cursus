/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:50:41 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 22:35:32 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static void	init_struct(t_info info)
{
	info.width = 0;
	info.zero = 0;
	info.space = 0;
	info.plus = 0;
	info.sharp = 0;
	info.minus = 0;
	info.precision = 0;
}

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
			init_struct(&info);
			parse_flag(&info, &(++format));
			parse_width(&info, &format);
			parse_precision(&info, &format);
			temp = parse_type(*format, ap);
			if (temp == -1)
				return (-1);
			print_len += temp;
		}
		else
		{
			print_len += write(1, format, 1);
		}
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
