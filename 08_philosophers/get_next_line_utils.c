/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:54:02 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/12 03:11:06 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*(const unsigned char *)s == (unsigned char)c)
			return ((char *)s);
		if (!*s)
			break ;
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*p2;

	s2 = malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	p2 = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (p2);
}

char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s || !len)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	sub[len] = '\0';
	while (len--)
		sub[len] = s[start + len];
	return (sub);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(len + 1);
	if (!join)
		return (NULL);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (join - len);
}
