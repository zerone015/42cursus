/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:28:38 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/04 15:27:33 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/minishell.h"

void	add_first(t_token *token, int type, char *str)
{
	t_tnode	*new;

	new = safe_malloc(sizeof(t_tnode));
	new->type = type;
	new->str = str;
	push(new, token);
}

void	add_last(t_token *token, int type, char *str)
{
	t_tnode	*new;

	new = safe_malloc(sizeof(t_tnode));
	new->type = type;
	new->str = str;
	push_back(new, token);
}

char	*remove_first(t_token *token)
{
	t_tnode	*first;
	char	*ret;

	first = pop(token);
	if (!first)
		return (NULL);
	ret = first->str;
	free(first);
	return (ret);
}

int	first_type(t_token *token)
{
	if (!token->head->next)
		return (-1);
	return (token->head->next->type);
}

int	last_type(t_token *token)
{
	if (!token->tail)
		return (-1);
	return (token->tail->type);
}
