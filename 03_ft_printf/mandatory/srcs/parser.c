/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:29:48 by yoson             #+#    #+#             */
/*   Updated: 2022/10/26 00:57:53 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_type(int (*types[])(va_list), va_list ap, int type)
{
	if (types[(unsigned char)type])
		return ((types[(unsigned char)type](ap)));
	else
		return (0);
}

int	parse_format(va_list ap, const char *format)
{
	int		(*types[256])(va_list);
	int		print_len;
	int		temp;

	init_array(types);
	print_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			temp = parse_type(types, ap, *format);
			if (temp == ERROR)
				return (ERROR);
			print_len += temp;
		}
		else
		{
			if (write(1, format, 1) == ERROR)
				return (ERROR);
			print_len += 1;
		}
		format++;
	}
	return (print_len);
}
