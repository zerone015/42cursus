/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:52:15 by yoson             #+#    #+#             */
/*   Updated: 2022/07/10 01:40:23 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*str;

	src_len = ft_strlen(src);
	str = (char *) malloc(sizeof(*str) * (src_len + 1));
	if (str == 0)
		return (0);
	while (*src != '\0')
		*str++ = *src++;
	*str = '\0';
	return (str - src_len);
}
