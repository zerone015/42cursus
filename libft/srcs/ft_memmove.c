/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:46:42 by yoson             #+#    #+#             */
/*   Updated: 2022/07/05 20:11:43 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

	if (dest == src || size < 1)
		return (dest);
	dest_temp = (unsigned char *) dest;
	src_temp = (unsigned char *) src;
	if (dest > src)
	{
		dest_temp += size - 1;
		src_temp += size - 1;
		while (size--)
		{
			*(dest_temp--) = *(src_temp--);
		}
		return (dest);
	}
	while (size--)
	{
		*(dest_temp++) = *(src_temp++);
	}
	return (dest);
}
