/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:44:22 by yoson             #+#    #+#             */
/*   Updated: 2022/08/09 14:46:20 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	clear_game(t_game *game)
{
	game->move_cnt++;
	printf("%zu \n", game->move_cnt);
	printf("game clear!\n");
	exit(0);
}

void	move_up(t_game *g)
{
	t_map	*map;
	size_t	i;

	map = g->map;
	i = 0;
	while (++i < ft_strlen(map->str))
	{
		if (map->str[i] == 'P')
			break ;
	}
	if (map->str[i - map->width] == 'C')
		g->coll_cnt++;
	if (map->str[i - map->width] == 'E' && map->coll_sum == g->coll_cnt)
		clear_game(g);
	else if (map->str[i - map->width] != '1' && map->str[i - map->width] != 'E')
	{
		map->str[i] = '0';
		map->str[i - map->width] = 'P';
		g->move_cnt++;
		printf("%zu \n", g->move_cnt);
		draw_map(g->map, g->img, g->mlx, g->win);
	}
}

void	move_left(t_game *g)
{
	t_map	*map;
	size_t	i;

	map = g->map;
	i = 0;
	while (++i < ft_strlen(map->str))
	{
		if (map->str[i] == 'P')
			break ;
	}
	if (map->str[i - 1] == 'C')
		g->coll_cnt++;
	if (map->str[i - 1] == 'E' && map->coll_sum == g->coll_cnt)
		clear_game(g);
	else if (map->str[i - 1] != '1' && map->str[i - 1] != 'E')
	{
		map->str[i] = '0';
		map->str[i - 1] = 'P';
		g->move_cnt++;
		printf("%zu \n", g->move_cnt);
		draw_map(g->map, g->img, g->mlx, g->win);
	}
}

void	move_down(t_game *g)
{
	t_map	*map;
	size_t	i;

	map = g->map;
	i = 0;
	while (++i < ft_strlen(map->str))
	{
		if (map->str[i] == 'P')
			break ;
	}
	if (map->str[i + map->width] == 'C')
		g->coll_cnt++;
	if (map->str[i + map->width] == 'E' && map->coll_sum == g->coll_cnt)
		clear_game(g);
	else if (map->str[i + map->width] != '1' && map->str[i + map->width] != 'E')
	{
		map->str[i] = '0';
		map->str[i + map->width] = 'P';
		g->move_cnt++;
		printf("%zu \n", g->move_cnt);
		draw_map(g->map, g->img, g->mlx, g->win);
	}
}

void	move_right(t_game *g)
{
	t_map	*map;
	size_t	i;

	map = g->map;
	i = 0;
	while (++i < ft_strlen(map->str))
	{
		if (map->str[i] == 'P')
			break ;
	}
	if (map->str[i + 1] == 'C')
		g->coll_cnt++;
	if (map->str[i + 1] == 'E' && map->coll_sum == g->coll_cnt)
		clear_game(g);
	else if (map->str[i + 1] != '1' && map->str[i + 1] != 'E')
	{
		map->str[i] = '0';
		map->str[i + 1] = 'P';
		g->move_cnt++;
		printf("%zu \n", g->move_cnt);
		draw_map(g->map, g->img, g->mlx, g->win);
	}
}
