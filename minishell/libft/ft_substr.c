/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:21:01 by yoson             #+#    #+#             */
/*   Updated: 2022/08/31 22:44:33 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *src, int start, int len)
{
	char	*str;
	int		i;

	if (ft_strlen(src) <= start)
		return (ft_strdup(""));
	if (ft_strlen(src) < start + len)
		len = ft_strlen(src) - start;
	str = safe_malloc(sizeof(char) * (len + 1));
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
