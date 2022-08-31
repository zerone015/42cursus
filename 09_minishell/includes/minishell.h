/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:13:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/31 14:17:47 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "list.h"
# include "../libft/libft.h"

enum e_type
{
	NUL,
	WORD,
	PIPE,
	REDIRECT,
	S_QUOTES,
	D_QUOTES
};

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

void	update_pwd(t_list *env);
char	*get_prompt(t_list *env);

#endif
