/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:14:34 by yoson             #+#    #+#             */
/*   Updated: 2022/07/12 22:04:11 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	s1_c;
	unsigned char	s2_c;

	while (n--)
	{
		s1_c = *s1;
		s2_c = *s2;
		if (s1_c != s2_c || s1_c == '\0')
			return (s1_c - s2_c);
		s1++;
		s2++;
	}
	return (0);
}
