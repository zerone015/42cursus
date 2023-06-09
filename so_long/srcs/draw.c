/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:02:07 by yoson             #+#    #+#             */
/*   Updated: 2022/08/11 22:00:16 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

static void	array_init(void *img_arr[], t_img *img)
{
	img_arr['1'] = img->wall;
	img_arr['C'] = img->coll;
	img_arr['P'] = img->cha;
	img_arr['E'] = img->exit;
	img_arr['0'] = img->land;
}

void	draw_map(t_map *map, t_img *img, void *m, void *w)
{
	void			*img_arr[IMG_ARRAY_SIZE];
	unsigned char	c;
	size_t			hei;
	size_t			wid;

	array_init(img_arr, img);
	hei = 0;
	while (hei < map->height)
	{
		wid = 0;
		while (wid < map->width)
		{
			c = (unsigned char) map->str[hei * map->width + wid];
			mlx_put_image_to_window(m, w, img_arr[c], wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
}
