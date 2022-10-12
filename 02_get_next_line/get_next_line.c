/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:06:48 by yoson             #+#    #+#             */
/*   Updated: 2022/10/13 02:30:12 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static	char	*ft_free(char *ptr)
{
	free(ptr);
	return (NULL);
}

static char	*read_line(int fd, char *buffer, char *backup)
{
	int		read_size;
	char	*temp;

	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		if (read_size == -1)
			return (ft_free(backup));
		buffer[read_size] = '\0';
		temp = backup;
		backup = ft_strjoin(backup, buffer);
		free(temp);
		if (!backup)
			return (NULL);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	if (backup[0] == '\0')
		return (ft_free(backup));
	free(buffer);
	return (backup);
}

static char	*substring(char **backup)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while ((*backup)[i] != '\n' && (*backup)[i] != '\0')
		i++;
	line = ft_substr(*backup, 0, i + 1);
	if (line && (*backup)[i] == '\n')
	{
		temp = *backup;
		*backup = ft_substr(*backup, i + 1, ft_strlen(*backup) - i - 1);
		free(temp);
		if (!*backup)
			return (ft_free(line));
	}
	else
	{
		free(*backup);
		*backup = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
			return (ft_free(buffer));
	}
	backup = read_line(fd, buffer, backup);
	if (!backup)
		return (ft_free(buffer));
	line = substring(&backup);
	return (line);
}
