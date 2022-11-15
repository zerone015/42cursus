/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:48:00 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/15 21:11:40 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "../../includes/minishell.h"

int	builtin_pwd(int argc, char *argv[], t_env *env)
{
	char	buf[PATH_MAX];

	(void)argc;
	(void)argv;
	if (getcwd(buf, sizeof(buf)))
		ft_putendl_fd(buf, STDOUT_FILENO);
	else
		return (error(env, NULL, 1));
	env->exit_code = EXIT_SUCCESS;
	return (0);
}
