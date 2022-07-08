/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:21:01 by yoson             #+#    #+#             */
/*   Updated: 2022/07/08 20:42:27 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*temp;

	temp = (char *) malloc(len + 1);
	if (temp == 0)
		return (0);
	str = str + start;
	while (len--)
	{
		*temp = *str;
		temp++;
		str++;
	}	
	*temp = '\0';
	return (temp);
}
