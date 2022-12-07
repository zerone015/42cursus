/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:06:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/07 00:57:35 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_token(t_token *token) //test
{
	t_tnode	*node;
	int		index;

	node = token->head->next;
	index = 1;
	while (node)
	{
		printf("%d:%s$\n", index++, node->str);
		node = node->next;
	}
	printf("\n");
}

t_anode	*ast_new(t_token *data)
{
	t_anode	*node;

	node = safe_malloc(sizeof(t_anode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	ast_insert(t_token *tokens, t_anode **ast_ptr)
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

void	ast_preorder(t_anode *ast)
{
	if (!ast)
		return ;
	print_token(ast->data);
	ast_preorder(ast->left);
	ast_preorder(ast->right);
}

t_anode	*list_to_ast(t_token *tokens)
{
	t_anode	*ast;

	ast = NULL;
	ast_insert(tokens, &ast);
	ast_preorder(ast);
	exit(0); //test
	return (ast);
}
