/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:44:28 by yoson             #+#    #+#             */
/*   Updated: 2022/08/08 04:27:05 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>

int	main(int argc, char *argv[])
{
	t_map	map;

	if (!is_arguments_valid(argc, argv[1]))
		error("bad arguments");
	if (parse_map(&map, argv[1]) == ERROR)
		error("Parsing failed");
	if (!is_map_valid(&map))
		error("Invalid map");
	return (0);
}
