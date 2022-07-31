/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:06:48 by yoson             #+#    #+#             */
/*   Updated: 2022/08/01 06:29:22 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
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

	read_size = 1;
	while (read_size)
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
	return (backup);
}

static char	*substr_one_line(char *temp)
{
	char	*line;
	int		i;

	if (temp == NULL || temp[0] == '\0')
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = ft_substr(temp, 0, i + 1);
	return (line);
}

static char	*substr_backup(char *temp, char **line)
{
	char	*backup;
	int		i;

	if (temp == NULL)
		return (NULL);
	if (temp[0] == '\0')
		return (ft_free(temp));
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\0')
		return (ft_free(temp));
	backup = ft_substr(temp, i + 1, ft_strlen(temp) - i - 1);
	if (!backup)
	{
		free(*line);
		*line = NULL;
		return (ft_free(temp));
	}
	free(temp);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
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
			return (ft_free(buffer));
	}
	temp = read_line(fd, buffer, backup);
	free(buffer);
	line = substr_one_line(temp);
	backup = substr_backup(temp, &line);
	return (line);
}
