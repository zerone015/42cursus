/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:06:24 by yoson             #+#    #+#             */
/*   Updated: 2022/07/18 19:21:32 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <limits.h>

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

	if (!(**line))
		return (ft_free(line));
	i = 0;
	while ((*line)[i] != '\n' && (*line)[i] != '\0')
		i++;
	if ((*line)[i] == '\0' || (*line)[i + 1] == '\0')
		return (NULL);
	temp = ft_substr(*line, 0, i + 1);
	if (!temp)
		return (ft_free(line));
	backup = ft_substr(*line, i + 1, ft_strlen(*line) - i - 1);
	if (!backup)
	{
		free(temp);
		return (ft_free(line));
	}
	free(*line);
	*line = temp;
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!backup[fd])
	{
		backup[fd] = ft_strdup("");
		if (!backup[fd])
		{
			free(buffer);
			return (NULL);
		}
	}
	line = read_line(fd, buffer, backup[fd]);
	free(buffer);
	if (!line)
		return (NULL);
	backup[fd] = substr_line(&line);
	return (line);
}
