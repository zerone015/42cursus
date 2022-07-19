/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:40:54 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 03:10:48 by yoson            ###   ########.fr       */
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
		return ;
	print(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

static int	get_nbrlen(unsigned int n)
{
	int	print_len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	print_len;

	if (!n)
		return (zero_print());
	print(n);
	print_len = get_nbrlen(n);
	return (print_len);
}
