/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:10:44 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/05 00:17:47 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../includes/minishell.h"

int	error(t_env *env, char *err_msg, int status)
{
	if (!err_msg)
		err_msg = strerror(errno);
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(err_msg, 2);
	env->exit_code = status;
	return (ERROR);
}

void	child_error(char *err_msg, char *cmd, int status)
{
	if (!err_msg)
		err_msg = strerror(errno);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(status);
}
