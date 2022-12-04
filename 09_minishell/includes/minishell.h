/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:13:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/04 17:50:46 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE	1
# define FALSE	0

# include <stdio.h> //test
# include <unistd.h>
# include "builtin.h"
# include "env.h"
# include "get_next_line.h"
# include "priority.h"
# include "token.h"
# include "wildcard.h"
# include "../libft/libft.h"

enum e_fd
{
	READ_FD,
	WRITE_FD
};

enum e_type
{
	WORD,
	BLANK,
	REDIRECT,
	LOGICAL,
	PIPE,
	PARENTHESIS,
};

enum e_signal
{
	CHILD,
	PARENT
};

typedef struct s_exec
{
	int		std_fd[2];
	int		pipe_fd[2];
	t_env	*env;
	t_token	*token;
	char	**heredocs;
}	t_exec;

char	*get_prompt(t_env *env);
int		check_syntax(char **input, t_env *env);
t_token	*tokenize(char *input, t_env *env);
void	child_external(t_exec *exec);
void	child_execve(char *argv[], char *envp[]);
void	execute_command(char *input, t_exec *exec);
int		find_argv_size(t_token *token);
char	**make_argv(t_token *token, int *flag);
void	execute(char **argv, char **envp);
t_token	*parse_token(t_token *tokens);
int		has_heredoc(t_token *token);
int		is_builtin(t_token *token);
void	set_signal(int status);
void	safe_signal(int signum, void (*handler)(int));
void	echoctl(int flag);
void	redirection(t_token *token, int *flag);
char	*merge_word(t_token *token);
int		is_input_blank(char *input);
int		get_abs(int num);
int		is_stdin(char *input);
void	ft_free(char **argv);

void	child_builtin(t_exec *exec);
int		is_builtin(t_token *token);
int		wait_all(pid_t last_pid, int *is_sigint);
int		is_exit(t_tnode *first);
t_token	*parse_token(t_token *tokens);
int		is_normal_terminated(int status);
int		is_quit(int status);
int		find_exit_code(int status, int is_sigint);

int		ft_isredirect(char *input);
int		tokenize_redirect(char *input, t_token *token);
int		is_normal(char *input);
int		tokenize_normal(char *input, t_token *token);
int		tokenize_null(t_token *token);
int		tokenize_operator(char *input, t_token *token);
int		tokenize_parenthesis(char *input, t_token *token);
int		heredoc(t_token *token, t_exec *exec);
int		is_heredoc(t_tnode *node);
int		has_heredoc(t_token *token);
int		parent_heredoc(t_token *token, t_exec *exec);
void	child_heredoc(t_token *token, t_exec *exec);
void	clear_heredocs(t_exec *exec);
t_tnode	*find_heredoc_limiter(t_tnode *node);
t_tnode	*skip_blank(t_tnode *node);
char	*parse_input(char *input, t_env *env);

int		error(t_env *env, char *err_msg, int exit_code);
void	child_error(char *err_msg, char *cmd, int exit_code);

#endif
