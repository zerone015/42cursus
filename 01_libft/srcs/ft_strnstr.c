/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:44:27 by yoson             #+#    #+#             */
/*   Updated: 2022/07/09 02:23:29 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	j;

	if (*to_find == '\0')
		return ((char *) str);
	i = 0;
	while (str[i] != '\0' && i < size)
	{
		j = 0;
		while (str[i] == to_find[j] && str[i] != '\0')
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *) str + i - j);
		i -= j;
		i++;
	}
	return (0);
}
