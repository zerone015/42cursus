/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:39:41 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 17:09:27 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

int	print_char(va_list ap, t_info *info)
{
	char	c;
	int		print_len;

	if (info->width >= INT_MAX)
		return (ERROR);
	print_len = 0;
	if (info->minus == DISABLE)
		print_len += putnchar(' ', info->width - 1);
	c = va_arg(ap, int);
	print_len += write(1, &c, 1);
	if (info->minus == ENABLE)
		print_len += putnchar(' ', info->width - 1);
	return (print_len);
}
