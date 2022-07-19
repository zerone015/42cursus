/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_toupper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:54:16 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 03:14:25 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	zero_print(void)
{
	return (write(1, "0", 1));
}

static void	print(unsigned int n)
{
	if (!n)
		return (0);
	print(n / 16);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
}

static int	get_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_puthex_toupper(unsigned int n)
{
	int	print_len;

	if (!n)
		return (zero_print());
	print(n);
	print_len = get_hexlen(n);
	return (print_len);
}
