/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:04:52 by yoson             #+#    #+#             */
/*   Updated: 2022/07/10 18:19:20 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*nbr_str;
	int			is_negative;
	int			len;
	long long	nbr;

	nbr = n;
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		nbr *= -1;
	}
	len = ft_nbrlen(n) + is_negative;
	nbr_str = (char *) malloc(sizeof(char) * (len + 1));
	if (!nbr_str)
		return (0);
	nbr_str[len--] = '\0';
	while (nbr)
	{
		nbr_str[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (is_negative)
		nbr_str[len] = '-';
	return (nbr_str);
}
