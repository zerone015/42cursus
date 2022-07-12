/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:21:01 by yoson             #+#    #+#             */
/*   Updated: 2022/07/12 18:16:30 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;

	if (!src)
		return (0);
	if (ft_strlen(src) <= start)
		return (ft_strdup(""));
	if (ft_strlen(src) < len)
		len = ft_strlen(src);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	src += start;
	count = 0;
	while (*src && len--)
	{
		*str++ = *src++;
		count++;
	}
	*str = '\0';
	return (str - count);
}
