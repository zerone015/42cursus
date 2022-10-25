/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:00:42 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 17:27:08 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	else
		return (FALSE);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_itoa(char *buf, uintptr_t n, int radix, const char *base)
{
	int	len;

	len = find_len(n, radix);
	if (n == 0)
		buf[0] = base[0];
	while (n)
	{
		buf[--len] = base[n % radix];
		n /= radix;
	}
}

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)dest;
	while (n--)
		*temp++ = (unsigned char)c;
	return (dest);
}

void	ft_strncpy(char *dest, const char *src, size_t n)
{
	while (*src && n)
	{
		*dest++ = *src++;
		n--;
	}
}
