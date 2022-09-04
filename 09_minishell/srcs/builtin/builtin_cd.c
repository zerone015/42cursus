/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:47:50 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/04 18:19:28 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_path(int argc, char *argv[], t_env *env)
{
	if (argc == 1)
		return (find_key(env, "HOME")->val);
	if (ft_strcmp(argv[1], "-") == 0)
		return (find_key(env, "OLDPWD")->val);
	return (argv[1]);
}

int	builtin_cd(int argc, char *argv[], t_env *env)
{
	char	*path;

	path = get_path(argc, argv, env);
	if (chdir(path) == ERROR)
	{
		if (argc == 1)
			return (error(env, NULL, 1));
		return (builtin_error(env, "cd", argv[1], NULL));
	}
	if (argc > 1 && ft_strcmp(argv[1], "-") == 0)
		ft_putendl_fd(path, STDOUT_FILENO);
	return (0);
}
