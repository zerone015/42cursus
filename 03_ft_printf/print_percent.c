/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:12:54 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 17:17:14 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

int	print_percent(t_info *info)
{
	int	print_len;

	if (info->width >= INT_MAX)
		return (ERROR);
	print_len = 0;
	if (info->minus == DISABLE && info->zero == DISABLE)
		print_len += putnchar(' ', info->width - 1);
	else if (info->minus == DISABLE && info->zero == ENABLE)
		print_len += putnchar('0', info->width - 1);
	print_len += write(1, "%", 1);
	if (info->minus == ENABLE && info->width > 0)
		print_len += putnchar(' ', info->width - 1);
	return (print_len);
}
