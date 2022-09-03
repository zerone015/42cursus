/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:47:54 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 21:53:55 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtin_env(int argc, char *argv[], t_env *env)
{
	t_enode	*node;

	(void)argc;
	(void)argv;
	node = env->head->next;
	while (node)
	{
		if (node->val)
		{
			ft_putstr_fd(node->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(node->val, 1);
		}
		node = node->next;
	}
}
