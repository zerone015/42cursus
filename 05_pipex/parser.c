/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:37:26 by yoson             #+#    #+#             */
/*   Updated: 2022/07/28 22:22:18 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

int	parse_envp(t_info *info, char *envp[])
{
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 4))
		i++;
	info->path = ft_split(envp[i] + 5, ':');
	if (!info->path)
		return (ERROR);
	return (0);
}

int	parse_argv(t_info *info, char *argv[], int )
{

}
