/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:22:30 by yoson             #+#    #+#             */
/*   Updated: 2022/08/09 10:20:47 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <stddef.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define TRUE	1
# define FALSE	0

typedef struct s_map
{
	size_t	width;
	size_t	height;
	char	*str;
	size_t	coll_sum;
}	t_map;

typedef struct s_img
{
	void	*wall;
	void	*land;
	void	*exit;
	void	*cha;
	void	*coll;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;
	size_t	move_cnt;
	size_t	coll_cnt;
}	t_game;

t_game	*game_init(void);
void	img_init(t_img *img, void *mlx_ptr);
int		is_map_valid(t_map *map);
int		is_arguments_valid(int argc, char *filename);
void	parse_map(t_map *map, char *filename);
void	draw_map(t_map *map, t_img *img, void *m, void *w);
int		clear_game(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);
void	error(char *msg);

#endif
