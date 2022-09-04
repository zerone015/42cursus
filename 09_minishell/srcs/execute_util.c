/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:20:26 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/04 23:21:08 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_executable(char *cmd)
{
	int	fd;

	fd = open(cmd, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

int	is_directory(char *cmd)
{
	DIR	*result;

	result = opendir(cmd);
	if (!result)
		return (FALSE);
	closedir(result);
	return (TRUE);
}