/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:21:12 by yoson             #+#    #+#             */
/*   Updated: 2022/07/10 01:50:59 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t size)
{
	unsigned char	*str_tmp;

	str_tmp = (unsigned char *) str;
	while (size--)
		*str_tmp++ = 0;
}
