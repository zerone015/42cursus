/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:33:34 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 17:17:01 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>
#include <limits.h>

static int	print_sign(t_info *info, int nbr)
{
	int	print_len;

	print_len = 0;
	if (info->plus == ENABLE && nbr >= 0)
		print_len += write(1, "+", 1);
	else if (info->space == ENABLE && nbr >= 0)
		print_len += write(1, " ", 1);
	else if (nbr < 0)
		print_len += write(1, "-", 1);
	return (print_len);
}

static int	sign_exists(t_info *info, int nbr)
{
	if (info->space == ENABLE && nbr >= 0)
		return (1);
	if (info->plus == ENABLE || nbr < 0)
		return (1);
	return (0);
}

static int	get_nbrlen(int nbr, t_info *info)
{
	int	len;

	if (info->dot == ENABLE && info->precision == 0 && nbr == 0)
		return (0);
	len = 0;
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static int	print(char nbr_arr[], int n, int len)
{
	int	print_len;

	if (n == -2147483648)
		return (write(1, "2147483648", 10));
	if (len == 0)
		return (0);
	if (n < 0)
		n *= -1;
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

int	print_nbr(va_list ap, t_info *info)
{
	char		nbr_arr[11];
	int			nbr;
	int			print_len;

	if (info->width >= INT_MAX)
		return (ERROR);
	nbr = va_arg(ap, int);
	info->width -= get_max(info->precision, get_nbrlen(nbr, info)) + \
		sign_exists(info, nbr);
	print_len = 0;
	if (info->minus == DISABLE && info->zero == DISABLE)
		print_len += putnchar(' ', info->width);
	else if (info->minus == DISABLE && info->zero == ENABLE)
	{
		print_len += print_sign(info, nbr);
		print_len += putnchar('0', info->width);
	}
	if (info->zero == DISABLE)
		print_len += print_sign(info, nbr);
	print_len += putnchar('0', info->precision - get_nbrlen(nbr, info));
	print_len += print(nbr_arr, nbr, get_nbrlen(nbr, info));
	if (info->minus == ENABLE)
		print_len += putnchar(' ', info->width);
	return (print_len);
}
