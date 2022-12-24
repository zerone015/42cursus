/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:54:48 by yoson             #+#    #+#             */
/*   Updated: 2022/12/23 21:18:16 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "cub3d.h"

int	set_texture(char **texture, const char *line)
{
	char	*texture_path;

	texture_path = ft_strtrim(line, " ");
	if (!texture_path || ft_strchr(texture_path, ' '))
		return (ERROR);
	*texture = texture_path;
	return (0);
}

int	parse_error_handler(const char *filename)
{
	if (errno)
		ft_perror(NULL);
	else
		ft_error(filename, "Invalid file content");
}

int	is_cub_file(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (FALSE);
	filename = filename + len - 4;
	if (ft_strncmp(filename, ".cub", ft_strlen(filename)) != 0)
		return (FALSE);
	return (TRUE);
}

int is_map_line(char *line)
{
    const char  *map_set = " \n012NSEW";

    if (*line == '\0')
        return (FALSE);
    while (*line)
    {
        if (!ft_strchr(map_set, *line))
            return (FALSE);
        line++;
    }
    return (TRUE);
}