/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:38:53 by yoson             #+#    #+#             */
/*   Updated: 2022/07/10 01:40:53 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (str - len);
}
