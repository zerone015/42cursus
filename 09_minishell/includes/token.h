/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:39:07 by yoson             #+#    #+#             */
/*   Updated: 2022/12/02 13:48:55 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "env.h"

typedef struct s_tnode
{
	int				type;
	char			*str;
	struct s_tnode	*next;
}	t_tnode;

typedef struct s_token
{
	t_tnode	*head;
	t_tnode	*tail;
}	t_token;

void	push(t_tnode *node, t_token *stack);
t_tnode	*pop(t_token *stack);
void	add_first(t_token *token, int type, char *str);
void	add_last(t_token *token, int type, char *str);
char	*remove_first(t_token *token);
int		first_type(t_token *token);
int		last_type(t_token *token);
t_token	*init_token(void);
void	rotate(t_token *token);
void	redirect_to_last(t_token *token);
void	clear_token(t_token *token);
int		free_dquotes(char *word);

#endif
