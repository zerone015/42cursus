/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:57:10 by yoson             #+#    #+#             */
/*   Updated: 2022/09/01 21:52:24 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

t_token	*init_token(void)
{
	t_token	*token;

	token = safe_malloc(sizeof(t_token));
	token->head = safe_malloc(sizeof(t_tnode));
	token->head->str = ft_strdup("");
	token->tail = token->head;
	return (token);
}

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

int	get_first_type(t_token *token)
{
	if (!token->head->next)
		return (ERROR);
	return (token->head->next->type);
}

void	redirect_to_last(t_token *token)
{
	int		pipe;

	if (!token->head->next)
		return ;
	pipe = 0;
	if (token->head->next->type == PIPE)
	{
		pipe = 1;
		remove_first(token);
		if (token->head->next->type == BLANK)
			remove_first(token);
	}
	if (token->head->next->type == REDIRECT)
	{
		rotate(token);
		if (token->head->next->type == BLANK)
			remove_first(token);
		while (token->head->next->type == WORD)
			rotate(token);
	}
	if (pipe)
		add_first(token, PIPE, "|");
}

void	rotate(t_token *token)
{
	t_tnode	*first;

	if (!token->head->next || !token->head->next->next)
		return ;
	first = token->head->next;
	token->head->next = first->next;
	token->tail->next = first;
	token->tail = first;
	first->next = NULL;
}
