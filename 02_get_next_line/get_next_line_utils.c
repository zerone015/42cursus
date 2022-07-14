/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:07:26 by yoson             #+#    #+#             */
/*   Updated: 2022/07/14 20:43:38 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\n')
		len++;
	len++;
	return (len);
}

char	*gnl_strdup(const char *src)
{
	char	*str;
	size_t	i;

	str = (char *) malloc(sizeof(char) * (gnl_strlen(src) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\n';
	str[i + 1] = '\0';
	return (str);
}

void	gnl_strlcpy(char *dest, const char *src, size_t len)
{
	if (!len)
		return ;
	while (--len)
		*dest++ = *src++;
	*dest = '\0';
}
