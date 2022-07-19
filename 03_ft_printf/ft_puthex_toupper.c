/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_toupper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:54:16 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 02:04:13 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	print(unsigned int n, int print_len)
{
	if (!n)
		return (0);
	print_len = print(n / 16, print_len);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
	print_len++;
	return (print_len);
}

int	ft_puthex_toupper(unsigned int n)
{
	int	print_len;

	print_len = 0;
	if (!n)
	{
		print_len += write(1, "0", 1);
		return (print_len);
	}
	print_len += print(n, 0);
	return (print_len);
}
