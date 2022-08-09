/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:00:06 by yoson             #+#    #+#             */
/*   Updated: 2022/08/09 10:23:18 by yoson            ###   ########.fr       */
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
	size_t	i;

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
	return (TRUE);
}

static int	is_all_char_valid(t_map *map)
{
	int		cnt[256];
	size_t	i;

	i = 0;
	while (i < 256)
		cnt[i++] = 0;
	i = 0;
	while (map->str[i] != '\0')
	{
		cnt[(unsigned char) map->str[i]]++;
		i++;
	}
	i = cnt['P'] + cnt['E'] + cnt['C'] + cnt['1'] + cnt['0'];
	if (ft_strlen(map->str) != i)
		return (FALSE);
	if (cnt['P'] != 1 || cnt['E'] == 0 || cnt['C'] == 0)
		return (FALSE);
	map->coll_sum = cnt['C'];
	return (TRUE);
}

int	is_arguments_valid(int argc, char *filename)
{
	size_t	len;

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
	if (!is_all_char_valid(map))
		return (FALSE);
	return (TRUE);
}
