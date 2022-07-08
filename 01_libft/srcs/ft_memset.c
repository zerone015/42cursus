/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:47:41 by yoson             #+#    #+#             */
/*   Updated: 2022/07/08 22:14:01 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int value, size_t size)
{
	unsigned char	*temp;

	temp = (unsigned char *) ptr;
	while (size--)
		*(temp++) = (unsigned char)value;
	return (ptr);
}
