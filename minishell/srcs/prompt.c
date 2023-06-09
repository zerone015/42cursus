/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:37:45 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/05 20:15:41 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "../includes/minishell.h"

void	update_pwd(t_env *env)
{
	t_enode	*pwd;
	t_enode	*old_pwd;
	char	*cwd;

	pwd = find_key(env, "PWD");
	old_pwd = find_key(env, "OLDPWD");
	cwd = getcwd(NULL, 0);
	if (!cwd)
		error(env, NULL, 1);
	if (ft_strcmp(cwd, pwd->val) == 0)
	{
		free(cwd);
		return ;
	}
	free(old_pwd->val);
	old_pwd->val = pwd->val;
	pwd->val = cwd;
}

char	*get_prompt(t_env *env)
{
	char	*pwd;

	update_pwd(env);
	pwd = find_key(env, "PWD")->val;
	if (ft_strlen(pwd) == 1)
		pwd = "/";
	else
		pwd = ft_strrchr(pwd, '/') + 1;
	return (ft_strjoin(pwd, "$ "));
}
