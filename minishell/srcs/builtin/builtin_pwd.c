/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:48:00 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:23:58 by kijsong          ###   ########.fr       */
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
	getcwd(buf, sizeof(buf));
	ft_putendl_fd(buf, STDOUT_FILENO);
	env->exit_code = EXIT_SUCCESS;
	return (0);
}
