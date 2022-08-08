/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:59:49 by yoson             #+#    #+#             */
/*   Updated: 2022/08/09 06:47:00 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>
#include <stdlib.h>

t_game	*game_init(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (NULL);
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		return (NULL);
	return (game);
}

void	img_init(t_img *img, void *mlx)
{
	int	w;
	int	h;

	img->wall = mlx_xpm_file_to_image(mlx, "./imgs/wall.xpm", &w, &h);
	img->land = mlx_xpm_file_to_image(mlx, "./imgs/land.xpm", &w, &h);
	img->exit = mlx_xpm_file_to_image(mlx, "./imgs/exit.xpm", &w, &h);
	img->cha = mlx_xpm_file_to_image(mlx, "./imgs/character.xpm", &w, &h);
	img->coll = mlx_xpm_file_to_image(mlx, "./imgs/collect.xpm", &w, &h);
}
