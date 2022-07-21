/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:40:54 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 17:20:57 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

static int	get_nbrlen(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static int	print(char nbr_arr[], unsigned int n, int len)
{
	int	print_len;

	nbr_arr[len--] = '\0';
	if (n == 0)
		nbr_arr[len] = '0';
	while (n > 0)
	{
		nbr_arr[len--] = n % 10 + '0';
		n /= 10;
	}
	print_len = write(1, nbr_arr, ft_strlen(nbr_arr));
	return (print_len);
}

int	print_unbr(va_list ap, t_info *info)
{
	char		nbr_arr[11];
	unsigned int	nbr;
	int			print_len;
	int			gap;

	if (info->width >= INT_MAX)
		return (ERROR);
	nbr = va_arg(ap, int);
	info->width -= get_max(info->precision, get_nbrlen(nbr));
	print_len = 0;
	if ((info->minus == DISABLE && info->zero == DISABLE) || \
		(info->minus == DISABLE && info->dot == ENABLE))
		print_len += putnchar(' ', info->width);
	else if (info->minus == DISABLE && info->zero == ENABLE)
		print_len += putnchar('0', info->width);
	gap = info->precision - get_nbrlen(nbr);
		gap--;
	print_len += putnchar('0', gap);
	print_len += print(nbr_arr, nbr, get_nbrlen(nbr));
	if (info->minus == ENABLE)
		print_len += putnchar(' ', info->width);
	return (print_len);
}
