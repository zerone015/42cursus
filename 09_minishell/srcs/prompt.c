/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:37:45 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/05 12:45:53 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "../includes/minishell.h"

void	update_pwd(t_env *env)
{
	t_enode	*pwd;
	t_enode	*old_pwd;
	char	buf[PATH_MAX];

	pwd = find_key(env, "PWD");
	old_pwd = find_key(env, "OLDPWD");
	if (!getcwd(buf, sizeof(buf)))
		error(env, NULL, 1);
	if (ft_strcmp(buf, pwd->val) == 0)
		return ;
	free(old_pwd->val);
	old_pwd->val = pwd->val;
	pwd->val = buf;
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
