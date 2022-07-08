/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:10:11 by yoson             #+#    #+#             */
/*   Updated: 2022/07/09 02:10:57 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *ptr, int value, size_t size)
{
	unsigned char	*ptr_tmp;

	ptr_tmp = (unsigned char *) ptr;
	while (size--)
	{
		if (*ptr_tmp == (unsigned char) value)
			return (ptr_tmp);
		ptr_tmp++;
	}
	return (0);
}
