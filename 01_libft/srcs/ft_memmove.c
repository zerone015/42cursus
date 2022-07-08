/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:46:42 by yoson             #+#    #+#             */
/*   Updated: 2022/07/09 01:52:47 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (dest == src || size < 1)
		return (dest);
	if (dest > src)
	{
		dest_tmp = (unsigned char *) dest + size - 1;
		src_tmp = (unsigned char *) src + size - 1;
		while (size--)
			*dest_tmp-- = *src_tmp--;
		return (dest);
	}
	dest_tmp = (unsigned char *) dest;
	src_tmp = (unsigned char *) src;
	while (size--)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}
