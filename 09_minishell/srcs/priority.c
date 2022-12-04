/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:44:42 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/04 16:50:58 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_token(t_token *token)
{
	t_tnode	*node;
	int		index;

	node = token->head->next;
	index = 1;
	while (node)
	{
		printf("%d: %s\n", index++, node->str);
		node = node->next;
	}
}

t_token	*infix_to_postfix(t_token *infix)
{
	t_token	*postfix;
	t_token	*operators;
	t_tnode	*node;
	t_tnode	*popped;

	postfix = init_token();
	operators = init_token();
	node = pop(infix);
	while (node)
	{
		if (node->type < LOGICAL)
			push_back(node, postfix);
		else
		{
			if (!ft_strcmp(node->str, ")"))
			{
				popped = pop(operators);
				while (ft_strcmp(popped->str, "("))
				{
					push_back(popped, postfix);
					popped = pop(operators);
				}
			}
			else
			{
				if (!get_stack_size(operators))
					push(node, operators);
				else
				{
					popped = pop(operators);
					if (get_priority(popped, TRUE) > get_priority(node, FALSE))
						push_back(popped, postfix);
					else
						push(popped, operators);
					push(node, operators);
				}
			}
		}
		node = pop(infix);
	}
	while (get_stack_size(operators))
		push_back(pop(operators), postfix);
	clear_token(infix);
	clear_token(operators);
	return (postfix);
}

t_token *calculate(t_token *postfix)
{
	t_token	*result;
	t_token	*stack;
	t_tnode	*node;
	t_tnode	*operand1;
	t_tnode	*operand2;

	result = init_token();
	stack = init_token();
	node = pop(postfix);
	while (node)
	{
		if (node->type < LOGICAL)
			push(node, stack);
		else
		{
			operand1 = pop(stack);
			if (!get_stack_size(result))
			{
				operand2 = pop(stack);
				push_back(operand2, result);
			}
			push_back(node, result);
			push_back(operand1, result);
		}
		node = pop(postfix);
	}
	clear_token(stack);
	return (result);
}
