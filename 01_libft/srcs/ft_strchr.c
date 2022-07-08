/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:35:28 by yoson             #+#    #+#             */
/*   Updated: 2022/07/09 02:14:01 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int value)
{
	while (*str != '\0')
	{
		if (*str == (char) value)
			return ((char *) str);
		str++;
	}
	if ((char) value == '\0')
		return ((char *) str);
	return (0);
}
