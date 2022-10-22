/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:50:10 by yoson             #+#    #+#             */
/*   Updated: 2022/10/23 02:51:28 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnchar(char c, int n)
{
	int	print_len;

	print_len = 0;
	while (n-- > 0)
		print_len += write(1, &c, 1);
	return (print_len);
}

void	ft_itoa(char *buf, uintptr_t n, int radix, const char *base)
{
	int	len;

	len = find_len(n, radix);
	if (n == 0)
		buf[0] = base[0];
	while (n)
	{
		buf[--len] = base[n % radix];
		n /= radix;
	}
}

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	find_len(size_t	n, int radix)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n /= radix;
	}
	return (len);
}
