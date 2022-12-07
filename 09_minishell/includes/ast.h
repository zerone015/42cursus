/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:58:45 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/06 23:49:14 by kijsong          ###   ########.fr       */
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

void	print_token(t_token *token); //test
int		validate_parenthesis(char *input);
t_token	*get_right(t_token *tokens);
t_token	*get_operator(t_token *right);
t_anode	*list_to_ast(t_token *tokens);

#endif
