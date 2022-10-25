/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:50:41 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 20:03:17 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	t_info	info;
	va_list	ap;
	int		print_len;

	init_array(&info);
	va_start(ap, format);
	print_len = parse_format(ap, format, &info);
	va_end(ap);
	return (print_len);
}
