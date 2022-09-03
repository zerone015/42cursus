/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:48:00 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 14:48:00 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include "minishell.h"

void	builtin_pwd(int argc, char *argv[], t_env *env)
{
	char	*buf[PATH_MAX];

	if (getcwd(buf, sizeof(buf)))
		ft_putendl_fd(buf, 1);
	else
		error(env, strerror(errno), 1);
}
