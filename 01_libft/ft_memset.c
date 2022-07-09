/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:47:41 by yoson             #+#    #+#             */
/*   Updated: 2022/07/10 02:06:25 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int c, size_t len)
{
	unsigned char	*mem_tmp;

	mem_tmp = (unsigned char *) mem;
	while (len--)
		*mem_tmp++ = (unsigned char) c;
	return (mem);
}
