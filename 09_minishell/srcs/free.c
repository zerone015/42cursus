/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:22:04 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/04 23:22:43 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	clear_token(t_token *token)
{
	t_tnode	*node;
	t_tnode	*temp;

	node = token->head;
	while (node)
	{
		temp = node->next;
		free(node->str);
		free(node);
		node = temp;
	}
	free(token);
}
