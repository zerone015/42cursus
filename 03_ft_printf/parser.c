/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:29:48 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 04:14:40 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	parse_flag(t_info *info, const char **format)
{
	(*format)++;
	while (info->flag[(unsigned char)**format])
	{
		*info->flag[(unsigned char)**format] = ENABLE;
		(*format)++;
	}
	if (info->plus == ENABLE && info->space == ENABLE)
		info->space = DISABLE;
	if (info->minus == ENABLE)
		info->zero = DISABLE;
}

static void	parse_width(t_info *info, const char **format)
{
	int	len;

	len = 0;
	while (ft_isdigit(**format) && len < INT_MAX_LEN)
	{
		info->width *= 10;
		info->width += **format - '0';
		(*format)++;
		len++;
	}
	while (ft_isdigit(**format))
		(*format)++;
}

static void	parse_precision(t_info *info, const char **format)
{
	int	len;

	if (**format == '.')
	{
		info->zero = DISABLE;
		info->dot = ENABLE;
		(*format)++;
		len = 0;
		while (ft_isdigit(**format) && len < INT_MAX_LEN)
		{
			info->precision *= 10;
			info->precision += **format - '0';
			(*format)++;
			len++;
		}
	}
}

static int	parse_type(t_info *info, va_list ap, int type)
{
	if (info->type[(unsigned char)type])
		return ((info->type[(unsigned char)type](ap, info)));
	else
		return (0);
}

int	parse_format(va_list ap, const char *format, t_info *info)
{
	int		print_len;
	int		temp;

	print_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			init_info(info);
			parse_flag(info, &format);
			parse_width(info, &format);
			parse_precision(info, &format);
			temp = parse_type(info, ap, *format++);
			if (temp == ERROR)
				return (ERROR);
			print_len += temp;
		}
		else
		{
			if (write(1, format++, 1) == ERROR)
				return (ERROR);
			print_len += 1;
		}
	}
	return (print_len);
}
