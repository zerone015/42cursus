/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:07:26 by yoson             #+#    #+#             */
/*   Updated: 2022/10/13 00:58:16 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remove_first(t_list *list)
{
	t_list	*temp;

	free(list->next->backup);
	temp = list->next->next;
	free(list->next);
	list->next = temp;
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	size;
	size_t	i;

	size = 0;
	while (str[size])
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*str)
		ret[i++] = *str++;
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	if ((char) c == '\0')
		return ((char *) str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*str;
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (src_len <= start)
		return (ft_strdup(""));
	if (src_len < start + len)
		len = src_len - start;
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
