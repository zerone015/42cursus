/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:22:30 by yoson             #+#    #+#             */
/*   Updated: 2022/08/08 04:38:12 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	int		width;
	int		height;
	char	*str;
}	t_map;

# define TRUE 1
# define FALSE 0
# define ERROR -1

int		parse_map(t_map *map, char *filename);
int		is_map_valid(t_map *map);
int		is_arguments_valid(int argc, char *filename);
void	error(char *msg);

#endif
