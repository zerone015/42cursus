/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:52:15 by yoson             #+#    #+#             */
/*   Updated: 2022/08/30 15:11:05 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	src_len;

	src_len = ft_strlen(src);
	str = safe_malloc(sizeof(char) * (src_len + 1));
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (str - src_len);
}
