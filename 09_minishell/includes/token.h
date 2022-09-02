/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:39:07 by yoson             #+#    #+#             */
/*   Updated: 2022/09/02 16:58:34 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define TRUE	1
# define FALSE	0

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

t_token	*init_token(void);
void	add_last(t_token *token, int type, char *str);
char	*remove_first(t_token *token);
int		first_type(t_token *token);
void	redirect_to_last(t_token *token);
void	rotate(t_token *token);

#endif
