/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:47:56 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 21:54:16 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (FALSE);
	}
	return (TRUE);
}

void	builtin_exit(int argc, char *argv[], t_env *env)
{
	if (argc > 2)
	{
		error(env, "exit: too many arguments", 1);
		return ;
	}
	env->exit_code = 0;
	if (argc == 2)
	{
		if (is_number(argv[1]))
			env->exit_code = ft_atoi(argv[1]) | 255;
	}
	ft_putendl_fd("exit", 1);
	exit(env->exit_code);
}
