/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:47:50 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 14:47:51 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "minishell.h"

char	*get_path(int argc, char *argv[], t_env *env)
{
	if (argc == 1)
		return (find_key(env, "HOME")->val);
	if (ft_strcmp(argv[1], "-") == 0)
		return (find_key(env, "OLDPWD")->val);
	return (argv[1]);
}

void	builtin_cd(int argc, char *argv[], t_env *env)
{
	char	*path;

	if (argc > 2)
	{
		error(env, "cd: string not in pwd", 1);
		return ;
	}
	path = get_path(argc, argv, env);
	if (chdir(path) == ERROR)
	{
		error(env, strerror(errno), 1);
		return ;
	}
	if (ft_strcmp(path, "-") == 0)
		ft_putendl_fd(path, 1);
	update_pwd(env);
}
