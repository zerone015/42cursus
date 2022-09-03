/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:47:52 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 14:47:53 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(int argc, char *argv[], t_env *env)
{
	int	i;
	int	n_flag;

	(void)env;
	i = 0;
	n_flag = 0;
	if (ft_strcmp(argv[1], "-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (++i < argc - 1)
	{
		ft_putstr_fd(argv[i], 1);
		ft_putchar_fd(' ', 1);
	}
	if (i == argc - 1)
		ft_putstr_fd(argv[i], 1);
	if (!n_flag)
		ft_putchar_fd('\n', 1);
}
