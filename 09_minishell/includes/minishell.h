/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:13:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/12 03:32:11 by yoson            ###   ########.fr       */
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

char	*get_prompt(t_env *env);
int		syntax_check(char **input, t_env *env);
t_token	*tokenize(char *input, t_env *env);
void	external_process(t_token *token, t_env *env, int fd[], int std_fd[]);
char	**preprocess(t_token *token, int fd[]);
void	execute(char **argv, char **envp);
t_token	*parse_token(t_token *tokens);
int		is_builtin(t_token *token);
int		is_directory(char *cmd);
int		is_executable(char *cmd);
void	set_signal(int status);
void	safe_signal(int signum, void (*handler)(int));
void	echoctl(int flag);
void	redirection(t_token *token, int *flag);

char	*merge_word(t_token *token);
int		is_input_blank(char *input);
int		get_abs(int num);
int		is_stdin(char *input);
void	ft_free(char **argv);

int		ft_isredirect(char *input);
int		tokenize_redirect(char *input, t_token *token);
int		is_normal(char c);
int		tokenize_normal(char *input, t_token *token);

int		error(t_env *env, char *err_msg, int exit_code);
void	child_error(char *err_msg, char *cmd, int exit_code);

#endif
