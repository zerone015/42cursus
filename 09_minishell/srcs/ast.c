/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:06:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 14:37:39 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_token	*get_operator(t_token *right)
{
	t_token	*operator;

	operator = init_token();
	push(pop(right), operator);
	return (operator);
}

static t_anode	*ast_new(t_token *data)
{
	t_anode	*node;

	node = safe_malloc(sizeof(t_anode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static void	ast_insert(t_token *tokens, t_anode **ast_ptr)
{
	t_token	*left;
	t_token	*right;

	right = get_right(tokens);
	if (!right)
	{
		*ast_ptr = ast_new(tokens);
		return ;
	}
	left = tokens;
	*ast_ptr = ast_new(get_operator(right));
	ast_insert(left, &(*ast_ptr)->left);
	ast_insert(right, &(*ast_ptr)->right);
}

t_anode	*list_to_ast(t_token *tokens)
{
	t_anode	*ast;

	ast = NULL;
	ast_insert(tokens, &ast);
	return (ast);
}
