/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:44:42 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/02 14:23:23 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h> //test

t_token	*init_infix(void)
{
	t_token	*infix;

	infix = init_token();
	add_last(infix, PARENTHESIS, ft_strdup("("));
	add_last(infix, WORD, ft_strdup("1"));
	add_last(infix, LOGICAL, ft_strdup("||"));
	add_last(infix, WORD, ft_strdup("2"));
	add_last(infix, PARENTHESIS, ft_strdup(")"));
	add_last(infix, PIPE, ft_strdup("|"));
	add_last(infix, WORD, ft_strdup("3"));
	print_token(infix);
	printf("\nConverting...\n\n");
	return (infix);
}

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
	t_token	*stack;
	t_tnode	*node;
	t_tnode	*popped;

	postfix = init_token();
	stack = init_token();
	node = infix->head->next;
	while (node)
	{
		if (node->type >= LOGICAL)
		{
			if (!ft_strcmp(node->str, ")"))
			{
				popped = pop(postfix);
				while (!ft_strcmp(node->str, "("))
				{
					push(node, postfix);
					popped = pop(postfix);
				}
			}
			else
			{
				if (!get_stack_size(stack))
					push(node, stack);
				else
				{
					popped = pop(stack);
					if (get_priority(popped, TRUE) > get_priority(node, FALSE))
						push(popped, postfix);
					else
						push(popped, stack);
				}
			}
		}
		else
			push(node, postfix);
		node = node->next;
	}
	while (get_stack_size(stack))
		push(pop(stack), postfix);
	return (postfix);
}
