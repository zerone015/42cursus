/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:23:12 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/04 16:41:18 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIORITY_H
# define PRIORITY_H

# include "token.h"
# include "../libft/libft.h"

int		get_priority(t_tnode *node, int in_stack);
int		get_stack_size(t_token *stack);
t_token	*infix_to_postfix(t_token *infix);
t_token	*calculate(t_token *postfix);
void	print_token(t_token *token); //test

#endif
