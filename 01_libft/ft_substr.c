/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:21:01 by yoson             #+#    #+#             */
/*   Updated: 2022/07/10 01:41:18 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*tmp;

	tmp = (char *) malloc(len + 1);
	if (tmp == 0)
		return (0);
	str = str + start;
	while (len--)
		*tmp++ = *str++;
	*tmp = '\0';
	return (temp);
}
