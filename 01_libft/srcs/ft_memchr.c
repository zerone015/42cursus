/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:10:11 by yoson             #+#    #+#             */
/*   Updated: 2022/07/08 22:13:25 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *str, int value, size_t size)
{
	unsigned char	*temp;

	temp = (unsigned char *) str;
	while (size--)
	{
		if (*temp == (unsigned char)value)
			return (temp);
		temp++;
	}
	return (0);
}
