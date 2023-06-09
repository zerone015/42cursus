/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:06:24 by yoson             #+#    #+#             */
/*   Updated: 2022/10/15 07:09:50 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static char	*substring(t_list *list)
{
	char	*line;
	char	*backup;
	char	*temp;
	int		i;

	backup = list->cur->backup;
	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	line = ft_substr(backup, 0, i + 1);
	if (line && backup[i] == '\n' && backup[i + 1] != '\0')
	{
		temp = ft_substr(backup, i + 1, ft_strlen(backup) - i - 1);
		if (!temp)
		{
			free(line);
			return (remove_fd(list));
		}
		free(list->cur->backup);
		list->cur->backup = temp;
	}
	else
		remove_fd(list);
	return (line);
}

static char	*read_file(t_list *list, char *buffer)
{
	char	*temp;
	int		read_size;

	while (1)
	{
		read_size = read(list->cur->fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		if (read_size == -1)
			return (NULL);
		buffer[read_size] = '\0';
		temp = list->cur->backup;
		list->cur->backup = ft_strjoin(list->cur->backup, buffer);
		free(temp);
		if (!list->cur->backup)
			return (NULL);
		if (ft_strchr(list->cur->backup, '\n'))
			break ;
	}
	if ((list->cur->backup)[0] == '\0')
		return (NULL);
	free(buffer);
	return (list->cur->backup);
}

static t_node	*find_fd(t_list *list, int fd)
{
	int	i;

	if (!list->tail)
		return (NULL);
	i = -1;
	while (++i < list->num_of_fd)
	{
		if (list->cur->fd == fd)
			return (list->cur);
		list->before = list->cur;
		list->cur = list->cur->next;
	}
	return (NULL);
}

static int	add_fd(t_list *list, int fd)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (-1);
	new->fd = fd;
	new->backup = malloc(1);
	if (!new->backup)
	{
		free(new);
		return (-1);
	}
	*new->backup = '\0';
	if (!list->tail)
	{
		list->tail = new;
		new->next = new;
	}
	new->next = list->tail->next;
	list->tail->next = new;
	list->before = list->tail;
	list->tail = new;
	list->cur = new;
	(list->num_of_fd)++;
	return (0);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static t_list	list;

	if (!find_fd(&list, fd))
	{
		if (add_fd(&list, fd) == -1)
			return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (remove_fd(&list));
	if (!read_file(&list, buffer))
	{
		free(buffer);
		return (remove_fd(&list));
	}
	line = substring(&list);
	return (line);
}
