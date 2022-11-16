/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/11/16 17:45:51 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../includes/minishell.h"
#include <fcntl.h>//지워야함 나중에 
char	*safe_readline(char *prompt)
{
	char	*input;

	input = readline(prompt);
	free(prompt);
	return (input);
}

void	child_builtin(t_exec *exec)
{
	char	**argv;
	int		out_redirection;
	
	dup2(exec->std_fd[0], STDIN_FILENO);
	close(exec->pipe_fd[0]);
	if (first_type(exec->token) == PIPE)
		free(remove_first(exec->token));
	out_redirection = 0;
	argv = make_argv(exec->token, &out_redirection);
	if (!out_redirection && first_type(exec->token) == PIPE)
		dup2(exec->pipe_fd[1], STDOUT_FILENO);
	close(exec->pipe_fd[1]);
	execute_builtin(argv, exec->env, TRUE);
}

int	is_builtin(t_token *token)
{
	t_tnode		*node;
	char		*cmd;
	char		*temp;
	const char	*builtin = "\0cd\0echo\0env\0exit\0export\0pwd\0unset";

	node = token->head->next;
	cmd = ft_strdup("");
	while (node && node->type == PIPE)
		node = node->next;
	while (node && node->type == WORD)
	{
		temp = cmd;
		cmd = ft_strjoin(cmd, node->str);
		free(temp);
		node = node->next;
	}
	temp = strnstr_strict(builtin, cmd, 35);
	free(cmd);
	if (!temp)
		return (FALSE);
	return (TRUE);
}

void	child_process(t_exec *exec)
{
	if (is_builtin(exec->token))
		child_builtin(exec);
	else
		child_external(exec);
}

void	parent_process(t_exec *exec)
{
	if (last_type(exec->token) == PIPE)
		dup2(exec->pipe_fd[0], STDIN_FILENO);
	else
		dup2(exec->std_fd[0], STDIN_FILENO);
	close(exec->pipe_fd[0]);
	close(exec->pipe_fd[1]);
	dup2(exec->std_fd[1], STDOUT_FILENO);
	clear_token(exec->token);
}

int	wait_all(pid_t last_pid)
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = 1;
	while (pid != -1)
	{
		pid = wait(&status);
		if (pid == last_pid)
			ret = status >> 8;
	}
	return (ret);
}

int	exit_program(t_token *tokens, t_env *env)
{
	int		argc;
	char	**argv;

	argc = find_argv_size(tokens);
	argv = make_argv(tokens, NULL);
	unlink("/tmp/.heredoc");
	if (argc >= 2 && !is_number(argv[1]))
	{
		builtin_error(env, "exit", argv[1], "numeric argument required");
		exit(255);
	}
	if (argc > 2)
	{
		ft_free(argv);
		return (builtin_error(env, "exit", NULL, "too many arguments"));
	}
	env->exit_code = 0;
	if (argc == 2)
	{
		if (is_number(argv[1]))
			env->exit_code = ft_atoi(argv[1]) & 255;
	}
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(env->exit_code);
	return (0);
}

int	is_exit(t_tnode *first)
{
	if (ft_strncmp(first->str, "exit", 5) == 0)
		return (TRUE);
	return (FALSE);
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
	while (type != PIPE && type != -1)
	{
		add_last(token, type, remove_first(tokens));
		type = first_type(tokens);
	}
	redirect_to_last(token);
	if (type == PIPE)
		add_last(token, PIPE, ft_strdup("|"));
	return (token);
}

void	execute_with_fork(t_token *tokens, t_exec *exec)
{
	pid_t	pid;
	
	while (first_type(tokens) != -1)
	{	
		exec->token = parse_token(tokens);
		if (pipe(exec->pipe_fd) == -1)
		{
			error(exec->env, NULL, 1);
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
			error(exec->env, NULL, 1);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			child_process(exec);
		else if (pid > 0)
			parent_process(exec);
	}
	exec->env->exit_code = wait_all(pid);
}

int	is_heredoc(t_tnode *node)
{
	if (node->type == REDIRECT && ft_strcmp(node->str, "<<") == 0)
		return (TRUE);
	return (FALSE);
}

int	has_heredoc(t_token *token)
{
	t_tnode	*node;

	node = token->head->next;
	while (node)
	{
		if (is_heredoc(node))
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

t_tnode	*skip_blank(t_tnode *node)
{
	while (node->type == BLANK)
		node = node->next;
	return (node);
}

t_tnode	*find_heredoc_limiter(t_tnode *node)
{
	while (node)
	{
		if (is_heredoc(node))
			return (skip_blank(node->next));
		node = node->next;
	}
	return (NULL);
}

char	*join_number(char *dest, int src)
{
	char	*str_src;
	char	*ret;

	str_src = ft_itoa(src);
	ret = ft_strjoin(dest, str_src);
	free(str_src);
	return (ret);
}

char *read_input(char *limiter)
{
	char	*line;
	char	*join;
	char	*temp;

	echoctl(FALSE);
	join = ft_strdup("");
	while (1)
	{
		ft_putstr_fd("> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || ft_strcmp(line, limiter) == 0)
			break ;
		temp = join;
		join = ft_strjoin(join, line);
		free(temp);
	}
	return (join);
}

void	input_to_file(char *input, char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		child_error(NULL, "heredoc", 1);
	write(fd, input, ft_strlen(input));
	close(fd);
}

int	find_heredocs_size(t_token *token)
{
	int		ret;
	t_tnode	*cur;

	ret = 0;
	cur = token->head->next;
	while (cur)
	{
		if (is_heredoc(cur))
			ret++;
		cur = cur->next;
	}
	return (ret);
}

void	set_heredocs(t_token *token, t_exec *exec)
{
	int	size;
	int	i;

	size = find_heredocs_size(token);
	exec->heredocs = safe_malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < size)
		(exec->heredocs)[i] = join_number("/tmp/.heredoc", i);
	(exec->heredocs)[i] = NULL;
}

void	make_heredocs(t_token *token, char **heredocs)
{
	t_tnode	*cur;
	char	*input;

	cur = find_heredoc_limiter(token->head->next);
	while (cur)
	{
		input = read_input(ft_strjoin(cur->str, "\n"));
		input_to_file(input, *heredocs++);
		free(input);
		cur = find_heredoc_limiter(cur);
	}
}

void	change_limiter_to_filename(t_token *token, t_exec *exec)
{
	t_tnode	*cur;
	int		i;

	cur = find_heredoc_limiter(token->head->next);
	i = 0;
	while (cur)
	{
		free(cur->str);
		cur->str = ft_strdup((exec->heredocs)[i++]);
		cur = find_heredoc_limiter(cur);
	}
}

int	is_normal_terminated(int status)
{
	if (status && status >> 8 == 0)
		return (FALSE);
	return (TRUE);
}

void	child_heredoc(t_token *token, char **heredocs)
{
	set_signal(CHILD);
	make_heredocs(token, heredocs);
	exit(EXIT_SUCCESS);
}

int	parent_heredoc(t_token *token, t_exec *exec)
{
	int		status;

	wait(&status);
	if (!is_normal_terminated(status))
	{
		exec->env->exit_code = EXIT_FAILURE;
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (-1);
	}
	change_limiter_to_filename(token, exec);
	return (0);
}

int	heredoc(t_token *token, t_exec *exec)
{
	pid_t	pid;
	int		res;

	set_heredocs(token, exec);
	pid = fork();
	if (pid == -1)
	{
		error(exec->env, NULL, 1);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child_heredoc(token, exec->heredocs);
	res = parent_heredoc(token, exec);
	return (res);
}

void	clear_heredocs(t_exec *exec)
{
	int	i;

	i = 0;
	if (!exec->heredocs)
		return ;
	while (exec->heredocs[i])
	{
		unlink(exec->heredocs[i]);
		free(exec->heredocs[i++]);
	}
	free(exec->heredocs);
	exec->heredocs = NULL;
}

void	execute_command(char *input, t_exec *exec)
{
	t_token	*tokens;
	int		heredoc_res;

	heredoc_res = 0;
	safe_signal(SIGINT, SIG_IGN);
	tokens = tokenize(input, exec->env);
	if (has_heredoc(tokens))
		heredoc_res = heredoc(tokens, exec);
	if (heredoc_res == 0)
	{
		if (is_exit(tokens->head->next) && !has_pipe(tokens))
			exit_program(tokens, exec->env);
		else if (is_builtin(tokens) && !has_pipe(tokens))
			execute_builtin(make_argv(tokens, NULL), exec->env, FALSE);
		else
			execute_with_fork(tokens, exec);
	}
	clear_token(tokens);
	clear_heredocs(exec);
}

void	parse_envp(t_env *env, char *envp[])
{
	int		i;

	while (*envp)
	{
		i = ft_strchr(*envp, '=') - *envp;
		add_enode(env, ft_substr(*envp, 0, i), \
						ft_substr(*envp, i + 1, ft_strlen(*envp)));
		envp++;
	}
}

void	init_exec(t_exec *exec, char *envp[])
{
	exec->heredocs = NULL;
	exec->std_fd[0] = dup(STDIN_FILENO);
	exec->std_fd[1] = dup(STDOUT_FILENO);
	exec->pipe_fd[0] = -1;
	exec->pipe_fd[1] = -1;
	exec->env = init_env();
	parse_envp(exec->env, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_exec	exec;
	char	*input;
	int		is_error;

	init_exec(&exec, envp);
	while (argc || argv)
	{
		set_signal(PARENT);
		input = safe_readline(get_prompt(exec.env));
		if (input)
		{
			is_error = check_syntax(&input, exec.env);
			if (*input)
				add_history(input);
			if (!is_error)
				execute_command(input, &exec);
			free(input);
		}
		else
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
