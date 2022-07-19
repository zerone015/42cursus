/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:40:54 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 02:06:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	put_nbr(unsigned int nbr)
{
	if (!nbr)
		return ;
	put_nbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

int	ft_putunbr(unsigned int n)
{
	int	print_len;

	print_len = 0;
	if (!n)
	{
		print_len += write(1, "0", 1);
		return (print_len);
	}
	put_nbr(n);
	while (n)
	{
		n /= 10;
		print_len++;
	}
	return (print_len);
}
