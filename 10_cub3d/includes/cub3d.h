/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:05:57 by yoson             #+#    #+#             */
/*   Updated: 2022/12/23 20:47:38 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ERROR				-1

enum e_bool
{
	FALSE,
	TRUE
};

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
	int		resolution[2];
	char	**map;
}	t_info;

void	parse_file(t_info *info, const char *filename);

#endif