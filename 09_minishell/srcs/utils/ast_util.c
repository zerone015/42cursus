/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:17:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/07 00:56:52 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	validate_parenthesis(char *input)
{
	int	depth;

	depth = 0;
	while (*input)
	{
		if (*input == '(')
			depth++;
		else if (*input == ')')
		{
			depth--;
			while (ft_isblank(*++input))
				;
			if (*input
			&& *input != ')'
			&& *input != '|'
			&& !ft_isredirect(input)
			&& ft_strncmp(input, "&&", 2))
				return (-1);
			continue ;
		}
		input++;
	}
	if (depth)
		return (-1);
	return (0);
}

static int	trim(t_lst *parentheses)
{
	t_tnode	*node;
	t_lst	*list;

	node = parentheses->content;
	node = node->next->next;
	while (node && node->type == BLANK)
		node = node->next;
	if (node)
		return (FALSE);
	list = parentheses;
	while (list)
	{
		node = list->content;
		delete_tnode(node, node->next);
		list = list->next;
	}
	ft_lstclear(&parentheses, NULL);
	return (TRUE);
}

static int	trim_parenthesis(t_tnode **curr_ptr)
{
	int		depth;
	t_lst	*parentheses;
	t_tnode	*curr;
	t_tnode	*next;

	curr = *curr_ptr;
	parentheses = NULL;
	ft_lstadd_front(&parentheses, ft_lstnew(curr));
	depth = 1;
	curr = curr->next;
	while (depth && curr->next)
	{
		next = curr->next;
		if (!ft_strcmp(next->str, "("))
			depth++;
		else if (!ft_strcmp(next->str, ")"))
			depth--;
		if (!depth)
			ft_lstadd_front(&parentheses, ft_lstnew(curr));
		curr = next;
	}
	*curr_ptr = curr;
	return (trim(parentheses));
}

static t_tnode	*get_delim(t_token *tokens)
{
	t_tnode	*delim;
	t_tnode	*curr;
	t_tnode	*next;

	delim = NULL;
	curr = tokens->head;
	while (curr && curr->next)
	{
		if (!ft_strcmp(curr->next->str, "(") && trim_parenthesis(&curr))
			curr = tokens->head;
		next = curr->next;
		if (next && next->type >= PIPE)
		{
			if (!delim)
				delim = curr;
			else if (next->type > delim->next->type)
				delim = curr;
		}
		curr = next;
	}
	return (delim);
}

t_token	*get_right(t_token *tokens)
{
	t_token	*right;
	t_tnode	*delim;

	delim = get_delim(tokens);
	if (!delim)
		return (NULL);
	right = init_token();
	right->head->next = delim->next;
	right->tail = tokens->tail;
	delim->next = NULL;
	tokens->tail = delim;
	return (right);
}

t_token	*get_operator(t_token *right)
{
	t_token	*operator;

	operator = init_token();
	push(pop(right), operator);
	return (operator);
}
