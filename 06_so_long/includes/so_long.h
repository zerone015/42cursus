/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:22:30 by yoson             #+#    #+#             */
/*   Updated: 2022/08/09 06:37:10 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <stddef.h>

typedef struct s_map
{
	size_t	width;
	size_t	height;
	char	*str;
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
}	t_game;

# define TRUE 1
# define FALSE 0
# define ERROR -1

t_game	*game_init(void);
void	img_init(t_img *img, void *mlx_ptr);
int		is_map_valid(t_map *map);
int		is_arguments_valid(int argc, char *filename);
int		parse_map(t_map *map, char *filename);
void	draw_map(t_map *map, t_img *img, void *m, void *w);
void	error(char *msg);

#endif
