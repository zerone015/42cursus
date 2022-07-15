/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:06:48 by yoson             #+#    #+#             */
/*   Updated: 2022/07/15 19:57:30 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	char			*line;
	static size_t	current;
	size_t			head;

	head = current;
	while (read(fd, &buffer[current], 1))
	{
		if (buffer[current] == '\n')
		{
			line = gnl_strdup(&buffer[head]);
			current++;
			return (line);
		}
		current++;
	}
	if (!(current - head))
		return (NULL);
	line = (char *) malloc(sizeof(char) * (current - head + 1));
	if (!line)
		return (NULL);
	gnl_strlcpy(line, &buffer[head], current - head + 1);
	return (line);
}
