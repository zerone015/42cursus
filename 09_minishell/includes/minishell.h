/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:13:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/04 23:25:26 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE	1
# define FALSE	0
# define ERROR	-1

# include <unistd.h>
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

enum e_signal
{
	CHILD,
	PARENT
};

void	update_pwd(t_env *env);
char	*get_prompt(t_env *env);
int		error(t_env *env, char *err_msg, int status);

char	**preprocess(t_token *token, int fd[]);
int		parent_process(t_token *token, int fd[], pid_t pid, int oldfd);
void	ft_free(char **argv);

void	safe_signal(int signum, void (*handler)(int));
void	set_signal(int status);
void	echoctl(int flag);

#endif
