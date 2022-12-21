/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:18:12 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 17:28:03 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ast_pipe(t_anode *ast, t_exec *exec)
{
	int	ret;
	int	pipe_fd[2];

	exec->has_pipe = TRUE;
	safe_pipe(pipe_fd, exec);
	dup2(pipe_fd[WRITE_FD], STDOUT_FILENO);
	close(pipe_fd[WRITE_FD]);
	ast_preorder(ast->left, exec);
	dup2(exec->std_fd[WRITE_FD], STDOUT_FILENO);
	dup2(pipe_fd[READ_FD], STDIN_FILENO);
	close(pipe_fd[READ_FD]);
	ret = ast_preorder(ast->right, exec);
	dup2(exec->std_fd[READ_FD], STDIN_FILENO);
	exec->has_pipe = FALSE;
	ret = 0;
	return (ret);
}

int	ast_logical_and(t_anode *ast, t_exec *exec)
{
	int	ret;

	ret = ast_preorder(ast->left, exec);
	if (ret == 0)
		ret = ast_preorder(ast->right, exec);
	return (ret);
}

int	ast_logical_or(t_anode *ast, t_exec *exec)
{
	int	ret;

	ret = ast_preorder(ast->left, exec) != 0;
	if (ret != 0)
		ret = ast_preorder(ast->right, exec);
	return (ret);
}

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

int	ast_preorder(t_anode *ast, t_exec *exec)
{
	// if (!ast)
	// 	return (0);
	// print_token(ast->data);
	// ast_preorder(ast->left, exec);
	// ast_preorder(ast->right, exec);
	// return (0);
	if (is_terminal_node(ast))
		return (execute_core(ast->data, exec));
	return (ast_operate(ast, exec));
}
