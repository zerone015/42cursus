/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:38 by yoson             #+#    #+#             */
/*   Updated: 2022/09/20 20:41:55 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "cub3d.h"

int	is_file_extension_valid(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (FALSE);
	if (ft_strcmp(filename + len - 4, ".cub") != 0)
		return (FALSE);
	return (TRUE);
}

void	parse_cubfile(t_info *info, const char *filename)
{
	int		fd;
	char	*line;

	if (!is_file_extension_valid(filename))
		error("Invalid file extension");
	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
		ft_perror(filename);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (set_info(info, ft_split(line, ' ')) == ERROR)
			error("Invalid file content");
		free(line);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	parse_cubfile(&info, argv[1]);
	return (0);
}
