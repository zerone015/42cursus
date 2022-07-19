/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:33:34 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 03:11:43 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	zero_print(void)
{
	return (write(1, "0", 1));
}

static void	print(long long nbr)
{
	if (!nbr)
		return ;
	print(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

static int	get_nbrlen(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long long	nbr;
	int			print_len;

	if (!n)
		return (zero_print());
	print_len = 0;
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		print_len += write(1, "-", 1);
	}
	print(nbr);
	print_len += get_nbrlen(n);
	return (print_len);
}
