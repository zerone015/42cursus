/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:44:28 by yoson             #+#    #+#             */
/*   Updated: 2022/08/09 06:46:43 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>

static void	*new_window(void *mlx, size_t width, size_t height)
{
	void	*win;

	win = mlx_new_window(mlx, width * 64, height * 64, "./so_long");
	return (win);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (!is_arguments_valid(argc, argv[1]))
		error("bad arguments");
	game = game_init();
	if (!game)
		error("Memory allocation failed");
	if (parse_map(game->map, argv[1]) == ERROR)
		error("Failed to read file");
	if (!is_map_valid(game->map))
		error("Invalid map");
	game->mlx = mlx_init();
	game->win = new_window(game->mlx, game->map->width, game->map->height);
	img_init(game->img, game->mlx);
	draw_map(game->map, game->img, game->mlx, game->win);
	mlx_loop(game->mlx);
	return (0);
}
