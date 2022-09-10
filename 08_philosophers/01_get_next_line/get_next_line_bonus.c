/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:20:15 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/07 10:05:03 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

static char	*ft_read_line(int fd, char *bkp)
{
	ssize_t	cnt;
	char	buf[BUFFER_SIZE + 1];
	char	*bkp_old;

	if (!bkp)
		bkp = ft_strdup("");
	while (bkp && !ft_strchr(bkp, '\n'))
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt == 0)
			break ;
		if (cnt == -1)
			return (ft_free(&bkp));
		buf[cnt] = '\0';
		bkp_old = bkp;
		bkp = ft_strjoin(bkp, buf);
		ft_free(&bkp_old);
	}
	return (bkp);
}

static char	*ft_get_line(char **bkp_new)
{
	size_t	i;
	char	*bkp;
	char	*line;

	i = 0;
	bkp = *bkp_new;
	if (bkp[i] == '\0')
		return (ft_free(bkp_new));
	while (bkp[i] != '\n' && bkp[i] != '\0')
		i++;
	if (bkp[i] == '\n')
		i++;
	line = ft_substr(bkp, 0, i);
	*bkp_new = ft_substr(bkp, i, ft_strlen(bkp) - i);
	ft_free(&bkp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*bkp[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	bkp[fd] = ft_read_line(fd, bkp[fd]);
	if (!bkp[fd])
		return (NULL);
	return (ft_get_line(bkp + fd));
}
