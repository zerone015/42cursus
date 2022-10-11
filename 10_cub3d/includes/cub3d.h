/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:05:57 by yoson             #+#    #+#             */
/*   Updated: 2022/09/21 11:56:17 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TRUE	1
# define FALSE	0
# define ERROR	-1

enum e_direction
{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_color
{
	int	floor[3];
	int	ceilling[3];
}	t_color;

typedef struct s_info
{
	char	*texture[4];
	t_color	color;
	char	*map;
}	t_info;

void	parse_file(t_info *info, const char *filename);

#endif