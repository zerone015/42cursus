/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:55:38 by yoson             #+#    #+#             */
/*   Updated: 2022/11/07 11:34:51 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	number_to_string(char *buf, uintptr_t n, int radix, const char *base)
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
