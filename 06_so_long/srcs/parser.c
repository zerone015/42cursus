/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:35:37 by yoson             #+#    #+#             */
/*   Updated: 2022/08/09 05:19:22 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	parse_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	map->str = get_next_line(fd);
	if (!map->str)
		return (ERROR);
	map->width = ft_strlen(map->str);
	map->height = 1;
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = map->str;
		map->str = ft_strjoin(map->str, line);
		if (!map->str)
			return (ERROR);
		free(line);
		free(temp);
		(map->height)++;
	}
	close(fd);
	return (0);
}
