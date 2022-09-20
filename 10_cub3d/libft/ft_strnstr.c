/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:44:27 by yoson             #+#    #+#             */
/*   Updated: 2022/09/03 23:35:16 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
