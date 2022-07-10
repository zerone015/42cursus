/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:10:11 by yoson             #+#    #+#             */
/*   Updated: 2022/07/10 02:02:20 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str_tmp;

	str_tmp = (unsigned char *) str;
	while (n--)
	{
		if (*str_tmp == (unsigned char) c)
			return (str_tmp);
		str_tmp++;
	}
	return (0);
}