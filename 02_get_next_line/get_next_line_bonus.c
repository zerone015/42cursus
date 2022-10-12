/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:06:24 by yoson             #+#    #+#             */
/*   Updated: 2022/10/13 02:54:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static int	add_first(t_list *list, int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (-1);
	new->fd = fd;
	new->backup = (char *)malloc(1);
	if (!new->backup)
	{
		free(new);
		return (-1);
	}
	*new->backup = '\0';
	new->next = list->next;
	list->next = new;
	return (0);
}

static char	*substring(t_list *list)
{
	char	*line;
	char	*backup;
	char	*temp;
	int		i;

	backup = list->next->backup;
	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	line = ft_substr(backup, 0, i + 1);
	if (line && backup[i] == '\n')
	{
		temp = ft_substr(backup, i + 1, ft_strlen(backup) - i - 1);
		if (!temp)
		{
			free(line);
			return (remove_first(list));
		}
		free(list->next->backup);
		list->next->backup = temp;
	}
	else
		remove_first(list);
	return (line);
}

static char	*read_line(t_list *list, char *buffer)
{
	char	*temp;
	int		read_size;

	while (1)
	{
		read_size = read(list->next->fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		if (read_size == -1)
			return (NULL);
		buffer[read_size] = '\0';
		temp = list->next->backup;
		list->next->backup = ft_strjoin(list->next->backup, buffer);
		free(temp);
		if (!list->next->backup)
			return (NULL);
		if (ft_strchr(list->next->backup, '\n'))
			break ;
	}
	if ((list->next->backup)[0] == '\0')
		return (NULL);
	free(buffer);
	return (list->next->backup);
}

static int	target_to_first(t_list *list, int fd)
{
	t_list	*cur;
	t_list	*prev;

	prev = NULL;
	cur = list->next;
	while (cur)
	{
		if (cur->fd == fd)
			break ;
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return (-1);
	if (prev)
	{
		prev->next = cur->next;
		cur->next = list->next;
		list->next = cur;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static t_list	list;

	if (target_to_first(&list, fd) == -1)
	{
		if (add_first(&list, fd) == -1)
			return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (remove_first(&list));
	if (!read_line(&list, buffer))
	{
		free(buffer);
		return (remove_first(&list));
	}
	line = substring(&list);
	return (line);
}
