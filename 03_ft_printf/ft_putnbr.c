/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:33:34 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 02:05:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	put_nbr(long long nbr)
{
	if (!nbr)
		return ;
	put_nbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

int	ft_putnbr(int n)
{
	long long	nbr;
	int			print_len;

	print_len = 0;
	if (!n)
	{
		print_len += write(1, "0", 1);
		return (print_len);
	}
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		print_len += write(1, "-", 1);
	}
	put_nbr(nbr);
	while (nbr)
	{
		nbr /= 10;
		print_len++;
	}
	return (print_len);
}
