/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:47:54 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:23:55 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_env(int argc, char *argv[], t_env *env)
{
	t_enode	*node;

	(void)argc;
	(void)argv;
	node = env->head->next;
	while (node)
	{
		if (node->val)
		{
			ft_putstr_fd(node->key, STDOUT_FILENO);
			ft_putchar_fd('=', STDOUT_FILENO);
			ft_putendl_fd(node->val, STDOUT_FILENO);
		}
		node = node->next;
	}
	env->exit_code = EXIT_SUCCESS;
	return (0);
}
