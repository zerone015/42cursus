/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:06:48 by yoson             #+#    #+#             */
/*   Updated: 2022/07/14 20:52:57 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*buffer_head;
	char		*line;
	size_t		len;

	buffer_head = buffer;
	len = 0;
	while (read(fd, buffer, 1) != -1)
	{
		if (*buffer == '\n')
		{
			line = gnl_strdup(buffer_head);
			buffer++;
			return (line);
		}
		len++;
		buffer++;
	}
	line = (char *) malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	gnl_strlcpy(line, buffer_head, len + 1);
	return (line);
}
