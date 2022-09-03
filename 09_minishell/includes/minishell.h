/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:13:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 23:05:02 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE	1
# define FALSE	0
# define ERROR	-1

# include "env.h"
# include "token.h"
# include "builtin.h"
# include "get_next_line.h"
# include "../libft/libft.h"

enum e_type
{
	WORD,
	BLANK,
	PIPE,
	REDIRECT
};

void	update_pwd(t_env *env);
char	*get_prompt(t_env *env);
int		error(t_env *env, char *err_msg, int status);

char	*child_preprocess(t_token *token, int fd[]);
int		parent_process(t_token *token, int fd[], pid_t pid, int oldfd);

void	receive_signal(void); //signal.h 분리?

#endif
