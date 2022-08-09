/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:57:18 by yoson             #+#    #+#             */
/*   Updated: 2022/08/09 15:09:38 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_W)
		move_up(game);
	else if (key == KEY_A)
		move_left(game);
	else if (key == KEY_S)
		move_down(game);
	else if (key == KEY_D)
		move_right(game);
	else if (key == KEY_ESC)
		exit_game(game);
	return (0);
}
