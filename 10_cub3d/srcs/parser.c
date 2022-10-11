/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:51:58 by yoson             #+#    #+#             */
/*   Updated: 2022/09/21 11:56:08 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "cub3d.h"

static int	is_cub_file(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (FALSE);
	if (ft_strcmp(filename + len - 4, ".cub") != 0)
		return (FALSE);
	return (TRUE);
}

static int	parse_line(t_info *info, const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (set_texture(&info->texture[NO], line));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (set_texture(&info->texture[SO], line));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (set_texture(&info->texture[WE], line));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (set_texture(&info->texture[EA], line));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (set_color(info->color.floor, line));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (set_color(info->color.ceilling, line));
	else if (ft_strncmp(line, "\n", 1) == 0)
		return (0);
	else if (is_map_content(line))
		return (set_map(&info->map, line));
	else
		return (ERROR);
}

void	parse_file(t_info *info, const char *filename)
{
	int		fd;
	char	*line;

	if (!is_cub_file(filename))
		error("Invalid file extension");
	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
		ft_perror(filename);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parse_line(info, line) == ERROR)
			error("Invalid file content");
		free(line);
	}
	close(fd);
}
