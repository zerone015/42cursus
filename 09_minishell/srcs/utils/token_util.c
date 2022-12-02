/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:28:38 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/02 12:48:26 by kijsong          ###   ########.fr       */
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
	new->next = token->head->next;
	token->head->next = new;
	if (!new->next)
		token->tail = new;
}

void	add_last(t_token *token, int type, char *str)
{
	t_tnode	*new;

	new = safe_malloc(sizeof(t_tnode));
	new->type = type;
	new->str = str;
	new->next = NULL;
	token->tail->next = new;
	token->tail = new;
}

char	*remove_first(t_token *token)
{
	t_tnode	*first;
	char	*ret;

	if (!token->head->next)
		return (NULL);
	first = token->head->next;
	ret = first->str;
	token->head->next = first->next;
	free(first);
	if (!token->head->next)
		token->tail = NULL;
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
