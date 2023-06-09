/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:27:08 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:24:06 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_terminal_node(t_anode *ast)
{
	if (!ast->left && !ast->right)
		return (TRUE);
	return (FALSE);
}

void	clear_ast(t_anode *ast)
{
	if (!ast)
		return ;
	clear_ast(ast->left);
	clear_ast(ast->right);
	clear_token(ast->data);
	free(ast);
}
