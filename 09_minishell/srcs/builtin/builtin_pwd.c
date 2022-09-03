/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:48:00 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 21:53:31 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "../../includes/minishell.h"

void	builtin_pwd(int argc, char *argv[], t_env *env)
{
	char	buf[PATH_MAX];

	(void)argc;
	(void)argv;
	if (getcwd(buf, sizeof(buf)))
		ft_putendl_fd(buf, 1);
	else
		error(env, NULL, 1);
}
