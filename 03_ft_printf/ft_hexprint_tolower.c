/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexprint_tolower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:34:58 by yoson             #+#    #+#             */
/*   Updated: 2022/07/19 22:35:00 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	recursive_print(unsigned int n, int len)
{
	if (!n)
		return (0);
	len = recursive_print(n / 16, len);
	write(1, &"0123456789abcdef"[n % 16], 1);
	len++;
	return (len);
}

int	ft_hexprint_tolower(unsigned int n)
{
	int	len;

	len = 0;
	if (!n)
	{
		len += write(1, "0", 1);
		return (len);
	}
	len += recursive_print(n, 0);
	return (len);
}
