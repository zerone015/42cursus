/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:06:48 by yoson             #+#    #+#             */
/*   Updated: 2022/07/12 20:30:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*str;

	while (read(fd, buffer, 1))
	{
		if (*buffer == '\n')
		{
			str = ft_strdup(buffer);
		}
		buffer++;
	}
}
