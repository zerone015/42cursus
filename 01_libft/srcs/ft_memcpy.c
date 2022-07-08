/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:36:18 by yoson             #+#    #+#             */
/*   Updated: 2022/07/09 01:40:53 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t size)
{	
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	dest_tmp = (unsigned char *) dest;
	src_tmp = (unsigned char *) src;
	if (dest == src)
		return (dest);
	while (size--)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}
