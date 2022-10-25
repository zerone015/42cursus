/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:55:38 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 17:58:23 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_ntoa(char *buf, uintptr_t n, int radix, const char *base)
{
	int	len;

	len = ft_nbrlen(n, radix);
	if (n == 0)
		buf[0] = base[0];
	while (n)
	{
		buf[--len] = base[n % radix];
		n /= radix;
	}
}
