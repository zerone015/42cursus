/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:21:01 by yoson             #+#    #+#             */
/*   Updated: 2022/07/12 22:05:25 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_len(char const *src, unsigned int start)
{
	size_t	len;

	len = 0;
	src += start;
	while (src[len])
		len++;
	return (len);
}

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!src)
		return (NULL);
	if (ft_strlen(src) <= start)
		return (ft_strdup(""));
	if (ft_strlen(src) < len)
		len = get_len(src, start);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	src += start;
	i = 0;
	while (src[i] && len--)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
