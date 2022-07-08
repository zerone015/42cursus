/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:47:41 by yoson             #+#    #+#             */
/*   Updated: 2022/07/09 02:11:41 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int value, size_t size)
{
	unsigned char	*ptr_tmp;

	ptr_tmp = (unsigned char *) ptr;
	while (size--)
		*ptr_tmp++ = (unsigned char) value;
	return (ptr);
}
