/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:48:02 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:23:59 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_essential(char *arg)
{
	if (ft_strcmp(arg, "HOME") == 0)
		return (TRUE);
	if (ft_strcmp(arg, "PWD") == 0)
		return (TRUE);
	if (ft_strcmp(arg, "OLDPWD") == 0)
		return (TRUE);
	return (FALSE);
}

int	builtin_unset(int argc, char *argv[], t_env *env)
{
	t_enode	*prev;
	t_enode	*curr;
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (is_essential(argv[i]))
			continue ;
		prev = env->head;
		while (prev && prev->next)
		{
			curr = prev->next;
			if (ft_strcmp(argv[i], curr->key) == 0)
			{
				delete_enode(env, prev, curr);
				break ;
			}
			prev = curr;
		}
	}
	env->exit_code = EXIT_SUCCESS;
	return (0);
}
