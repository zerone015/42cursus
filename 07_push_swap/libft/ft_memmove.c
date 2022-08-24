/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:46:42 by yoson             #+#    #+#             */
/*   Updated: 2022/07/17 23:32:23 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (!len || dest == src)
		return (dest);
	if (dest > src)
	{
		dest_tmp = (unsigned char *) dest + len - 1;
		src_tmp = (unsigned char *) src + len - 1;
		while (len--)
			*dest_tmp-- = *src_tmp--;
		return (dest);
	}
	dest_tmp = (unsigned char *) dest;
	src_tmp = (unsigned char *) src;
	while (len--)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}
