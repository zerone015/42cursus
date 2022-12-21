/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:58:45 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 18:09:42 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "token.h"

typedef struct s_anode
{
	t_token			*data;
	struct s_anode	*left;
	struct s_anode	*right;
}	t_anode;

int		validate_parenthesis(char *input);
t_token	*get_right(t_token *tokens);
t_anode	*list_to_ast(t_token *tokens);

int		is_terminal_node(t_anode *ast);
void	clear_ast(t_anode *ast);

#endif
