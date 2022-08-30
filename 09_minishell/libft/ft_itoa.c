/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:04:52 by yoson             #+#    #+#             */
/*   Updated: 2022/08/30 15:10:43 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_digit_len(int digit)
{
	int	len;

	len = 0;
	if (digit <= 0)
		len++;
	while (digit)
	{
		digit /= 10;
		len++;
	}
	return (len);
}

static long long	get_abs(int digit)
{
	long long	tmp;

	tmp = digit;
	if (digit < 0)
		tmp *= -1;
	return (tmp);
}

static char	*get_digit_str(char *digit_str, int digit, int len)
{
	long long	tmp;

	if (!digit)
	{
		digit_str[0] = '0';
		digit_str[1] = '\0';
		return (digit_str);
	}
	tmp = get_abs(digit);
	digit_str[len--] = '\0';
	while (tmp)
	{
		digit_str[len--] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (digit_str);
}

char	*ft_itoa(int n)
{
	char		*digit_str;
	int			len;

	len = get_digit_len(n);
	digit_str = safe_malloc(sizeof(char) * (len + 1));
	digit_str = get_digit_str(digit_str, n, len);
	if (n < 0)
		digit_str[0] = '-';
	return (digit_str);
}
