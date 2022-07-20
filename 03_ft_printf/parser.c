/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:29:48 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 07:01:43 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void	parse_flag(t_info *info, const char **format)
{
	while (is_flag(**format))
	{
		if (**format == ' ')
			info->space = ENABLE;
		else if (**format == '+')
			info->plus = ENABLE;
		else if (**format == '-')
			info->minus = ENABLE;
		else if (**format == '#')
			info->sharp = ENABLE;
		(*format)++;
	}
}

void	parse_width(t_info *info, const char **format)
{
	int	count;

	count = 0;
	if (**format == '0')
	{
		info->zero = ENABLE;
		while (**format != '0')
			(*format)++;
	}
	while (ft_isdigit(**format) && count < 10)
	{
		info->width *= 10;
		info->width += **format - '0';
		(*format)++;
		count++;
	}
	while (ft_isdigit(**format))
		(*format)++;
}

void	parse_precision(t_info *info, const char **format)
{
	if (**format == '.')
	{
		info->dot = ENABLE;
		(*format)++;
		while (ft_isdigit(**format))
		{
			info->precision *= 10;
			info->precision += **format - '0';
			(*format)++;
		}
	}
}

int	parse_type(t_info *info, va_list ap, char type)
{
	int	print_len;

	if (type == 'c')
		print_len = print_char(ap, info);
	else if (type == 's')
		print_len = ft_putstr(ap, info);
	else if (type == 'p')
		print_len = print_hex_address(ap, info);
	else if (type == 'd' || type == 'i')
		print_len = ft_putnbr(ap, info);
	else if (type == 'u')
		print_len = ft_putunbr(ap, info);
	else if (type == 'x')
		print_len = print_hex_lower(ap, info);
	else if (type == 'X')
		print_len = print_hex_upper(ap, info);
	else if (type == '%')
		print_len = print_percent(info);
	else
		print_len = 0;
	return (print_len);
}
