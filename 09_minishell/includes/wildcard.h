/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:26:36 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:23:49 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H
# define WILDCARD_H

# include <dirent.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_wildcard
{
	char	*pattern;
	char	*filename;
	int		p_len;
	int		f_len;
	int		**caches;
}	t_wildcard;

int		match_wildcard(char *pattern, struct dirent *file);
void	convert_wildcard(char *word, t_lst **argv);

#endif
