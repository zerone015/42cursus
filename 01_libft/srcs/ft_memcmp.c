/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:49:42 by yoson             #+#    #+#             */
/*   Updated: 2022/07/05 22:07:27 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;
	size_t		i;

	s1_temp = (unsigned char *) s1;
	s2_temp = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (*(s1_temp + i) != *(s2_temp + i))
			return (*(s1_temp + i) - *(s2_temp + i));
		i++;
	}
	return (0);
}
