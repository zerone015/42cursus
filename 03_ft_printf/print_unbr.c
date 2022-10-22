/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:40:54 by yoson             #+#    #+#             */
/*   Updated: 2022/10/23 02:53:23 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

static int	get_nbrlen(unsigned int nbr, t_info *info)
{
	int	len;

	if (info->dot == ENABLE && info->precision == 0 && nbr == 0)
		return (0);
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

	if (len == 0)
		return (0);
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
	char			nbr_arr[11];
	unsigned int	nbr;
	int				print_len;
	int				nbr_len;

	if (info->width >= INT_MAX)
		return (ERROR);
	nbr = va_arg(ap, int);
	nbr_len = get_nbrlen(nbr, info);
	info->width -= find_max(info->precision, nbr_len);
	print_len = 0;
	if (info->minus == DISABLE && info->zero == DISABLE)
		print_len += putnchar(' ', info->width);
	else if (info->minus == DISABLE && info->zero == ENABLE)
		print_len += putnchar('0', info->width);
	print_len += putnchar('0', info->precision - nbr_len);
	print_len += print(nbr_arr, nbr, nbr_len);
	if (info->minus == ENABLE)
		print_len += putnchar(' ', info->width);
	return (print_len);
}
