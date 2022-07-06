/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:36:18 by yoson             #+#    #+#             */
/*   Updated: 2022/07/05 19:45:26 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t size)
{	
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

	dest_temp = (unsigned char *) dest;
	src_temp = (unsigned char *) src;
	if (dest == src)
		return (dest);
	while (size--)
		*(dest_temp++) = *(src_temp++);
	return (dest);
}
