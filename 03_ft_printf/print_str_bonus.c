/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:06:59 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 17:20:42 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>
#include <limits.h>

int	print_str(va_list ap, t_info *info)
{
	const char	*str;
	int			print_len;
	size_t		str_len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (ft_strlen(str) >= INT_MAX)
		return (ERROR);
	if (info->precision < (int) str_len && info->precision > 0)
		str_len = info->precision;
	else if (info->dot == ENABLE && info->precision == 0)
		str_len = 0;
	print_len = 0;
	if (info->minus == DISABLE)
		print_len += putnchar(' ', info->width - str_len);
	print_len += write(1, str, str_len);
	if (info->minus == ENABLE)
		print_len += putnchar(' ', info->width - str_len);
	return (print_len);
}
