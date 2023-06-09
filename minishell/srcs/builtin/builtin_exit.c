/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:47:56 by kijsong           #+#    #+#             */
/*   Updated: 2023/02/16 19:25:51 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_exit(int argc, char *argv[], t_env *env)
{
	if (argc > 2 && is_number(argv[1]))
		return (builtin_error(env, "exit", NULL, "too many arguments"));
	if (argc == 1)
		env->exit_code = EXIT_SUCCESS;
	else if (argc == 2 && is_number(argv[1]))
		env->exit_code = ft_atoi(argv[1]) & 255;
	else
	{
		builtin_error(env, "exit", argv[1], "numeric argument required");
		env->exit_code = 255;
	}
	exit(env->exit_code);
	return (0);
}
