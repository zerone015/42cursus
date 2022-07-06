/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:44:57 by yoson             #+#    #+#             */
/*   Updated: 2022/07/05 20:11:33 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;
	size_t	j;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size < 1)
		return (src_len);
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		dest[i] = src[j];
		if (src[j] != '\0')
			j++;
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
