/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:52:15 by yoson             #+#    #+#             */
/*   Updated: 2022/07/11 21:47:53 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	src_len;

	src_len = ft_strlen(src);
	str = (char *) malloc(sizeof(char) * (src_len + 1));
	if (!str)
		return (0);
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (str - src_len);
}
