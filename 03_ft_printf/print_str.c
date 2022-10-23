/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:06:59 by yoson             #+#    #+#             */
/*   Updated: 2022/10/23 22:54:26 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static int	print_with_width(char *str, int len, t_info *info)
{
	char	*buf;
	int		print_len;

	buf = malloc(info->width);
	if (!buf)
		return (ERROR);
	if (info->minus == DISABLE)
	{
		ft_memset(buf, ' ', info->width - len);
		ft_strncpy(buf + info->width - len, str, len);
	}
	else
	{
		ft_strncpy(buf, str, len);
		ft_memset(buf + len, ' ', info->width - len);
	}
	print_len = write(1, buf, info->width);
	free(buf);
	return (print_len);
}

int	print_str(va_list ap, t_info *info)
{
	char	*str;
	size_t	len;

	if (info->width >= INT_MAX)
		return (ERROR);
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (len >= INT_MAX)
		return (ERROR);
	if (info->precision < (long long)len && info->precision > 0)
		len = info->precision;
	else if (info->dot == ENABLE && info->precision == 0)
		len = 0;
	if (info->width - (long long)len > 0)
		return (print_with_width(str, len, info));
	else
		return (write(1, str, len));
}
