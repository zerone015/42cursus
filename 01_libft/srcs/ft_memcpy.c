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

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t size)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < size)
	{
		*((unsigned char *) dest + i) = *((unsigned char *) src + i);
		i++;
	}
	return (dest);
}
