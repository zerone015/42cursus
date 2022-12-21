/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:47:52 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:23:54 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_echo(int argc, char *argv[], t_env *env)
{
	int	i;
	int	n_flag;

	i = 0;
	n_flag = 0;
	if (argc > 1 && ft_strcmp(argv[1], "-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (++i < argc - 1)
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (i == argc - 1)
		ft_putstr_fd(argv[i], STDOUT_FILENO);
	if (!n_flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
	env->exit_code = EXIT_SUCCESS;
	return (0);
}
