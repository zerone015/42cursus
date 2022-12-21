/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:18:12 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 18:43:16 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ast_operate(t_anode *ast, t_exec *exec)
{
	char	*operator;

	operator = ast->data->head->next->str;
	if (!ft_strcmp(operator, "|"))
		return (ast_pipe(ast, exec));
	if (!ft_strcmp(operator, "&&"))
		return (ast_logical_and(ast, exec));
	if (!ft_strcmp(operator, "||"))
		return (ast_logical_or(ast, exec));
	return (-1);
}

int	ast_preorder(t_anode *ast, t_exec *exec)
{
	if (is_terminal_node(ast))
		return (execute_core(ast->data, exec));
	return (ast_operate(ast, exec));
}
