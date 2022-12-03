/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:44:42 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/03 15:45:59 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h> //test

t_token	*init_infix(void)
{
	t_token	*infix;

	infix = init_token();
	add_last(infix, PARENTHESIS, ft_strdup("("));
	add_last(infix, WORD, ft_strdup("9"));
	add_last(infix, LOGICAL, ft_strdup("||"));
	add_last(infix, PARENTHESIS, ft_strdup("("));
	add_last(infix, WORD, ft_strdup("4"));
	add_last(infix, PIPE, ft_strdup("|"));
	add_last(infix, WORD, ft_strdup("2"));
	add_last(infix, LOGICAL, ft_strdup("&&"));
	add_last(infix, WORD, ft_strdup("1"));
	add_last(infix, PARENTHESIS, ft_strdup(")"));
	add_last(infix, PARENTHESIS, ft_strdup(")"));
	add_last(infix, PIPE, ft_strdup("|"));
	add_last(infix, PARENTHESIS, ft_strdup("("));
	add_last(infix, WORD, ft_strdup("5"));
	add_last(infix, PIPE, ft_strdup("|"));
	add_last(infix, WORD, ft_strdup("2"));
	add_last(infix, LOGICAL, ft_strdup("||"));
	add_last(infix, WORD, ft_strdup("2"));
	add_last(infix, PARENTHESIS, ft_strdup(")"));
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
		if (node->type < LOGICAL)
			add_first(postfix, node->type, ft_strdup(node->str));
			// push(node, postfix);
		else
		{
			if (!ft_strcmp(node->str, ")"))
			{
				popped = pop(stack);
				while (ft_strcmp(popped->str, "("))
				{
					push(popped, postfix);
					popped = pop(stack);
				}
			}
			else
			{
				if (!get_stack_size(stack))
					add_first(stack, node->type, ft_strdup(node->str));
					// push(node, stack);
				else
				{
					popped = pop(stack);
					if (get_priority(popped, TRUE) > get_priority(node, FALSE))
						push(popped, postfix);
					else
						push(popped, stack);
					add_first(stack, node->type, ft_strdup(node->str));
					// push(node, stak);
				}
			}
		}
		node = node->next;
	}
	while (get_stack_size(stack))
		push(pop(stack), postfix);
	while (get_stack_size(postfix))
		push(pop(postfix), stack);
	return (stack);
}
