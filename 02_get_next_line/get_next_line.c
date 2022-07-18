/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:06:48 by yoson             #+#    #+#             */
/*   Updated: 2022/07/18 14:25:44 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static	char	*ft_free(char **line)
{
	free(*line);
	*line = NULL;
	return (NULL);
}

static char	*read_line(int fd, char *buffer, char *backup)
{
	int		read_size;
	char	*temp;

	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		if (read_size == -1)
		{
			free(backup);
			return (NULL);
		}
		buffer[read_size] = '\0';
		temp = backup;
		backup = ft_strjoin(backup, buffer);
		free(temp);
		if (!backup)
			return (NULL);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	return (backup);
}

static	char	*substr_line(char **line)
{
	char	*backup;
	char	*temp;
	int		i;

	if (!*line[0])
		return (gnl_free(line));
	while (*line[i] != '\n' && *line[i] != '\0')
		i++;
	if (*line[i] == '\0' || *line[i + 1] == '\0')
		return (NULL);
	temp = ft_substr(*line, 0, i + 1);
	if (!temp)
		return (gnl_free(line));
	backup = ft_substr(*line, i + 1, ft_strlen(*line) - i - 1);
	if (!backup)
	{
		free(temp);
		return (gnl_free(line));
	}
	free(*line);
	*line = temp;
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;

	if (BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
		{
			free(buffer);
			return (NULL);
		}
	}
	line = read_line(fd, buffer, backup);
	free(buffer);
	if (!line)
		return (NULL);
	backup = substr_line(&line);
	return (line);
}
