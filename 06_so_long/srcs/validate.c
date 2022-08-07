/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:00:06 by yoson             #+#    #+#             */
/*   Updated: 2022/08/08 04:20:22 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_rectangle(t_map *map)
{
	if (map->width * map->height != ft_strlen(map->str))
		return (FALSE);
	return (TRUE);
}

static int	is_walls_surrounded(t_map *map)
{
	int	i;

	i = 0;
	while (map->str[i] != '\0')
	{
		if (i < map->width)
		{
			if (map->str[i] != '1')
				return (FALSE);
		}
		else if (i % map->width == 0 || i % map->width == map->width - 1)
		{
			if (map->str[i] != '1')
				return (FALSE);
		}
		else if (i > ft_strlen(map->str) - map->width)
		{
			if (map->str[i] != '1')
				return (FALSE);
		}
		i++;
	}
}

static int	p_e_c_exists(t_map *map)
{
	int	i;
	int	p_cnt;
	int	e_cnt;
	int	c_cnt;

	i = map->width;
	p_cnt = 0;
	e_cnt = 0;
	c_cnt = 0;
	while (i < ft_strlen(map->str) - map->width)
	{
		if (map->str[i] == 'P')
			p_cnt++;
		else if (map->str[i] == 'E')
			e_cnt++;
		else if (map->str[i] == 'C')
			c_cnt++;
		i++;
	}
	if (p_cnt != 1 || e_cnt == 0 || c_cnt == 0)
		return (FALSE);
	return (TRUE);
}

int	is_arguments_valid(int argc, char *filename)
{
	int		len;

	if (argc != 2)
		return (FALSE);
	len = ft_strlen(filename);
	if (len < 5)
		return (FALSE);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (FALSE);
	return (TRUE);
}

int	is_map_valid(t_map *map)
{
	if (!is_rectangle(map))
		return (FALSE);
	if (!is_walls_surrounded(map))
		return (FALSE);
	if (!p_e_c_exists(map))
		return (FALSE);
	return (TRUE);
}
