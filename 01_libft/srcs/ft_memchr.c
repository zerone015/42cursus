/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:10:11 by yoson             #+#    #+#             */
/*   Updated: 2022/07/05 21:49:12 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *str, int value, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *) str;
	i = 0;
	while (i < size)
	{
		if (*(temp + i) == value)
			return (temp + i);
		i++;
	}
	return (0);
}
