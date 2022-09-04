/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/09/04 23:29:53 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <string.h> //strerror
#include <term.h>
#include <unistd.h> //getcwd, pipe
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../includes/minishell.h"

void	update_pwd(t_env *env)
{
	t_enode	*pwd;
	t_enode	*old_pwd;
	char	buf[PATH_MAX];

	pwd = find_key(env, "PWD");
	old_pwd = find_key(env, "OLDPWD");
	if (!getcwd(buf, sizeof(buf)))
		error(env, NULL, 1);
	if (ft_strcmp(buf, pwd->val) == 0)
		return ;
	old_pwd->val = pwd->val;
	pwd->val = buf;
}

char	*get_prompt(t_env *env)
{
	char	*pwd;

	update_pwd(env);
	pwd = find_key(env, "PWD")->val;
	if (ft_strlen(pwd) == 1)
		pwd = "/";
	else
		pwd = ft_strrchr(pwd, '/') + 1;
	return (ft_strjoin(pwd, "$ "));
}

int	is_builtin(t_token *token)
{
	t_tnode		*node;
	char		*cmd;
	char		*temp;
	const char	*builtin = "\0cd\0echo\0env\0exit\0export\0pwd\0unset";

	node = token->head->next;
	cmd = ft_strdup("");
	while (node && node->type == WORD)
	{
		temp = cmd;
		cmd = ft_strjoin(cmd, node->str);
		free(temp);
		node = node->next;
	}
	temp = ft_strnstr(builtin, cmd, 35);
	free(cmd);
	if (!temp)
		return (FALSE);
	return (TRUE);
}

t_token	*parse_token(t_token *tokens)
{
	t_token	*token;
	int		type;

	token = init_token();
	if (first_type(tokens) == PIPE)
		add_last(token, PIPE, remove_first(tokens));
	if (first_type(tokens) == BLANK)
		free(remove_first(tokens));
	type = first_type(tokens);
	while (type != PIPE && type != ERROR)
	{
		add_last(token, type, remove_first(tokens));
		type = first_type(tokens);
	}
	redirect_to_last(token);
	if (type == PIPE)
		add_last(token, PIPE, ft_strdup("|"));
	return (token);
}

void	execute_command(char *input, t_env *env)
{
	t_token	*tokens;
	t_token	*token;
	int		fd[2];
	int		oldfd;

	safe_signal(SIGINT, SIG_IGN);
	oldfd = dup(STDIN_FILENO);
	tokens = tokenize(input, env);
	while (first_type(tokens) != ERROR)
	{
		token = parse_token(tokens);
		if (pipe(fd) == -1)
		{
			error(env, NULL, 1);
			exit(1);
		}
		if (is_builtin(token))
			builtin_process(token, env, fd, oldfd);
		else
			external_process(token, env, fd, oldfd);
		clear_token(token);
	}
	clear_token(tokens);
}

char	*safe_readline(char *prompt)
{
	char	*input;

	input = readline(prompt);
	free(prompt);
	return (input);
}

void exit_program(void)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(0);
}

t_env	*init_envp(char *envp[])
{
	t_env	*env;
	int		i;

	env = init_env();
	while (*envp)
	{
		i = ft_strchr(*envp, '=') - *envp;
		add_enode(env, ft_substr(*envp, 0, i), \
						ft_substr(*envp, i + 1, ft_strlen(*envp)));
		envp++;
	}
	return (env);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;
	int		is_error;

	env = init_envp(envp);
	while (argc || argv)
	{
		set_signal(PARENT);
		input = safe_readline(get_prompt(env));
		if (input)
		{
			is_error = syntax_check(&input, env);
			if (*input)
				add_history(input);
			if (!is_error)
				execute_command(input, env);
			free(input);
		}
		else
			exit_program();
	}
	return (0);
}
