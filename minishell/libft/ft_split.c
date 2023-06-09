/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:15:57 by yoson             #+#    #+#             */
/*   Updated: 2022/08/30 15:10:59 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_word(char c, char sep)
{
	if (c == sep)
		return (0);
	else
		return (1);
}

static size_t	get_size(const char *str, char sep)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		if (is_word(*str, sep))
		{
			size++;
			while (*str != '\0' && is_word(*str, sep))
				str++;
		}
		else
			str++;
	}
	return (size);
}

char	**get_str_array(char **str_array, char const *str, char sep)
{
	const char	*tmp;	
	size_t		i;

	i = 0;
	while (*str)
	{
		if (is_word(*str, sep))
		{
			tmp = str;
			while (*str && is_word(*str, sep))
				str++;
			str_array[i] = safe_malloc(sizeof(char) * (str - tmp + 1));
			ft_strlcpy(str_array[i++], tmp, str - tmp + 1);
		}
		else
			str++;
	}
	str_array[i] = NULL;
	return (str_array);
}

char	**ft_split(char const *str, char sep)
{
	char		**str_array;

	str_array = safe_malloc(sizeof(char *) * (get_size(str, sep) + 1));
	str_array = get_str_array(str_array, str, sep);
	return (str_array);
}
