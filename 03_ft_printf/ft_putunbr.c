/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:40:54 by yoson             #+#    #+#             */
/*   Updated: 2022/07/19 22:00:39 by yoson            ###   ########.fr       */
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
	int	len;

	len = 0;
	if (!n)
	{
		len += write(1, "0", 1);
		return (len);
	}
	put_nbr(n);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
