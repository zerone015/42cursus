/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:57:10 by yoson             #+#    #+#             */
/*   Updated: 2022/09/04 23:29:39 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*init_token(void)
{
	t_token	*token;

	token = safe_malloc(sizeof(t_token));
	token->head = safe_malloc(sizeof(t_tnode));
	token->head->str = ft_strdup("");
	token->tail = token->head;
	return (token);
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

void	redirect_to_last(t_token *token)
{
	int		pipe;

	if (!token->head->next)
		return ;
	pipe = 0;
	if (token->head->next->type == PIPE)
	{
		pipe = 1;
		free(remove_first(token));
		if (token->head->next && token->head->next->type == BLANK)
			free(remove_first(token));
	}
	if (token->head->next && token->head->next->type == REDIRECT)
	{
		rotate(token);
		if (token->head->next->type == BLANK)
			free(remove_first(token));
		while (token->head->next && token->head->next->type == WORD)
			rotate(token);
	}
	if (pipe)
		add_first(token, PIPE, ft_strdup("|"));
}
