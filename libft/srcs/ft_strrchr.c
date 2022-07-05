/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:56:18 by yoson             #+#    #+#             */
/*   Updated: 2022/07/05 21:09:31 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int value)
{
	char	*ptr;
	size_t	i;

	ptr = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == value)
		{
			ptr = str + i;
		}
		i++;
	}
	if (value == '\0')
		return (str + i);
	return (ptr);
}
