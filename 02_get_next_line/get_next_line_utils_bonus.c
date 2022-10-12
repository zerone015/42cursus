/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:07:26 by yoson             #+#    #+#             */
/*   Updated: 2022/10/13 01:23:48 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*remove_first(t_list *list)
{
	t_list	*temp;

	free(list->next->backup);
	temp = list->next->next;
	free(list->next);
	list->next = temp;
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(size + 1);
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
	size_t	i;

	if (ft_strlen(src) <= start)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (ft_strlen(src) < start + len)
		len = ft_strlen(src) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
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
