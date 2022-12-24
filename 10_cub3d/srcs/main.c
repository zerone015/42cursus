/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:38 by yoson             #+#    #+#             */
/*   Updated: 2022/12/23 20:47:44 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "cub3d.h"

static void	init_info(t_info *info)
{
	info->color.floor[0] = -1;
	info->color.ceilling[0] = -1;
	info->resolution[0] = -1;
	info->resolution[1] = -1;
	info->texture[NO] = NULL;
	info->texture[SO] = NULL;
	info->texture[WE] = NULL;
	info->texture[EA] = NULL;
	info->map = NULL;
}

int	main(int argc, char *argv[])
{
	t_info	info;

	init_info(&info);
	parse_file(&info, argv[1]);
	return (0);
}
