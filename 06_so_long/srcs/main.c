/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:44:28 by yoson             #+#    #+#             */
/*   Updated: 2022/08/09 11:14:09 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>

void	*new_window(void *mlx, size_t width, size_t height)
{
	void	*win;

	win = mlx_new_window(mlx, width * 64, height * 64, "./so_long");
	return (win);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	if (key == KEY_W)
		move_w(game);
	if (key == KEY_A)
		move_a(game);
	if (key == KEY_S)
		move_s(game);
	if (key == KEY_D)
		move_d(game);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (!is_arguments_valid(argc, argv[1]))
		error("bad arguments");
	game = game_init();
	parse_map(game->map, argv[1]);
	if (!is_map_valid(game->map))
		error("Invalid map");
	game->mlx = mlx_init();
	game->win = new_window(game->mlx, game->map->width, game->map->height);
	draw_map(game->map, game->img, game->mlx, game->win);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
