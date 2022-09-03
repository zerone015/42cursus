/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:48:02 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 14:48:03 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	builtin_unset(int argc, char *argv[], t_env *env)
{
	t_enode	*prev;
	t_enode	*curr;
	int		i;

	i = 0;
	while (++i < argc)
	{
		prev = env->head->next;
		while (prev && prev->next)
		{
			curr = prev->next;
			if (ft_strcmp(argv[i], curr->key) == 0)
			{
				prev->next = curr->next;
				delete_enode(curr);
				break ;
			}
			prev = curr;
		}
	}
}
