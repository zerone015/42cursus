/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:44:28 by yoson             #+#    #+#             */
/*   Updated: 2022/08/07 22:01:11 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char	**map;
	int		fd;
	
	if (!is_arguments_valid(argc, argv[1]))
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("File not found");
		return (EXIT_FAILURE);
	}
	map = parse_map(fd);
	if (!map)
		return (EXIT_FAILURE);
	return (0);
}
