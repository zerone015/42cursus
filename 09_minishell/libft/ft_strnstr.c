/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:44:27 by yoson             #+#    #+#             */
/*   Updated: 2022/11/12 04:03:36 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;

	while (*to_find && len--)
	{
		i = 0;
		while ((const unsigned char)str[i] == (const unsigned char)to_find[i])
		{
			if (*(str - 1))
				break ;
			if (!to_find[i++])
				return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
*/
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *)str);
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (str[i] == to_find[j] && str[i] && i < len)
		{
			i++;
			j++;
		}
		if (!to_find[j])
			return ((char *)str + i - j);
		i -= j;
		i++;
	}
	return (NULL);
}
