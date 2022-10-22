/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:00:42 by yoson             #+#    #+#             */
/*   Updated: 2022/10/23 03:10:00 by yoson            ###   ########.fr       */
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

int	is_flag(char c)
{
	if (c == ' ' || c == '+' || c == '#' || c == '-' || c == '0')
		return (TRUE);
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
