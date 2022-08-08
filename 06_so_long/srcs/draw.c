/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:02:07 by yoson             #+#    #+#             */
/*   Updated: 2022/08/09 06:18:52 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>

void	draw_map(t_map *map, t_img *img, void *m, void *w)
{
	size_t	hei;
	size_t	wid;

	hei = 0;
	while (hei < map->height)
	{
		wid = 0;
		while (wid < map->width)
		{
			if (map->str[hei * map->width + wid] == '1')
				mlx_put_image_to_window(m, w, img->wall, wid * 64, hei * 64);
			else if (map->str[hei * map->width + wid] == 'C')
				mlx_put_image_to_window(m, w, img->coll, wid * 64, hei * 64);
			else if (map->str[hei * map->width + wid] == 'P')
				mlx_put_image_to_window(m, w, img->cha, wid * 64, hei * 64);
			else if (map->str[hei * map->width + wid] == 'E')
				mlx_put_image_to_window(m, w, img->exit, wid * 64, hei * 64);
			else
				mlx_put_image_to_window(m, w, img->land, wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
}
