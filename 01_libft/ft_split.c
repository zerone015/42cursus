/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:15:57 by yoson             #+#    #+#             */
/*   Updated: 2022/07/10 01:40:08 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_word(char c, char charset)
{
	if (c == charset)
		return (0);
	else
		return (1);
}

size_t	get_size(const char *str, char charset)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		if (is_word(*str, charset))
		{
			size++;
			while (*str != '\0' && is_word(*str, charset))
				str++;
		}
		else
			str++;
	}
	return (size);
}

char	**free_all(char **str_array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
	return (0);
}

char	**ft_split(char const *str, char charset)
{
	char		**str_array;
	const char	*ptr;
	size_t		i;

	str_array = (char **) malloc(sizeof(char *) * (get_size(str, charset) + 1));
	if (!str_array)
		return (0);
	i = 0;
	while (*str)
	{
		if (is_word(*str, charset))
		{
			ptr = str;
			while (*str && is_word(*str, charset))
				str++;
			str_array[i] = (char *) malloc(sizeof(char) * (str - ptr + 1));
			if (!str_array[i])
				return (free_all(str_array, i));
			ft_strlcpy(str_array[i++], ptr, str - ptr + 1);
		}
		else
			str++;
	}
	str_array[i] = 0;
	return (str_array);
}
