/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print_toupper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:53:24 by yoson             #+#    #+#             */
/*   Updated: 2022/07/19 21:54:13 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	recursive_print(unsigned int n, int len)
{
	if (!n)
		return (0);
	len = recursive_print(n / 16, len);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
	len++;
	return (len);
}

int	ft_hex_print_toupper(unsigned int n)
{
	int	len;

	if (!n)
	{
		len += write(1, "0", 1);
		return (len);
	}
	len += recursive_print(n, 0);
	return (len);
}
