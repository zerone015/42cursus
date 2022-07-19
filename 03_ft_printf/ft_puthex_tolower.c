/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_tolower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:52:22 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 00:53:23 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	print(unsigned int n, int len)
{
	if (!n)
		return (0);
	len = print(n / 16, len);
	write(1, &"0123456789abcdef"[n % 16], 1);
	len++;
	return (len);
}

int	ft_puthex_tolower(unsigned int n)
{
	int	len;

	len = 0;
	if (!n)
	{
		len += write(1, "0", 1);
		return (len);
	}
	len += print(n, 0);
	return (len);
}
