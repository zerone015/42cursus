/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/09/04 13:07:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h> //strerror
#include <unistd.h> //getcwd, pipe
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../includes/minishell.h"

void	update_pwd(t_env *env)
{
	t_enode	*pwd;
	t_enode	*old_pwd;

	pwd = find_key(env, "PWD");
	old_pwd = find_key(env, "OLDPWD");
	old_pwd->val = pwd->val;
	pwd->val = getcwd(NULL, 0);
	if (!pwd->val)
		error(env, strerror(errno), 1);
}

char	*get_prompt(t_env *env)
{
	char	*pwd;
	char	*home;

	update_pwd(env);
	pwd = find_key(env, "PWD")->val;
	home = find_key(env, "HOME")->val;
	if (ft_strlen(pwd) == 1)
		pwd = "/";
	else
		pwd = ft_strrchr(pwd, '/') + 1;
	return (ft_strjoin(pwd, " $ "));
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

int	ft_isredirect(char *input)
{
	if (ft_strncmp(input, "<<", 2) == 0)
		return (2);
	else if (ft_strncmp(input, ">>", 2) == 0)
		return (-2);
	else if (*input == '<')
		return (1);
	else if (*input == '>')
		return (-1);
	return (0);
}

int	tokenize_envp(char *input, t_token *token, t_env *env)
{
	int		i;
	char	*key;
	t_enode	*node;

	i = 0;
	if (!ft_isalpha(input[i]) && input[i] != '_')
	{
		if (!ft_isdigit(input[i]) && input[i] != '?')
		{
			add_last(token, WORD, ft_strdup("$"));
			return (0);
		}
		if (input[i] == '?')
			add_last(token, WORD, ft_itoa(env->exit_code));
		return (1);
	}
	while (ft_isalpha(input[i]) || ft_isdigit(input[i]) || input[i] == '_')
		i++;
	key = ft_substr(input, 0, i);
	node = find_key(env, key);
	if (node)
		add_last(token, WORD, ft_strdup(node->val));
	free(key);
	return (i);
}

int	tokenize_dquotes(char *input, t_token *token, t_env *env)
{
	char	*word[2];
	char	*envp;
	int		start;

	if (!ft_strchr(input + 1, '"'))
	{
		add_last(token, WORD, ft_strdup("\""));
		return (0);
	}
	word[0] = ft_substr(input, 0, ft_strchr(input, '"') - input);
	start = 0;
	envp = ft_strchr(&word[0][start], '$');
	while (envp)
	{
		if (envp - word[0] - start > 0)
		{
			word[1] = ft_substr(word[0], start, envp - word[0] - start);
			add_last(token, WORD, word[1]);
			start += ft_strlen(word[1]);
		}
		start += tokenize_envp(envp + 1, token, env) + 1;
		envp = ft_strchr(&word[0][start], '$');
	}
	add_last(token, WORD, ft_substr(word[0], start, ft_strlen(word[0])));
	return (ft_strlen(word[0]) + 1);
}

int	tokenize_squotes(char *input, t_token *token)
{
	char	*word;

 	if (!ft_strchr(input + 1, '\''))
	{
		add_last(token, WORD, ft_strdup("'"));
		return (0);
	}
	word = ft_substr(input, 0, ft_strchr(input, '\'') - input);
	add_last(token, WORD, word);
	return (ft_strlen(word) + 1);
}

int	tokenize_space(char *input, t_token *token)
{
	int	i;

	i = 0;
	while (ft_isblank(input[i]))
		i++;
	add_last(token, BLANK, ft_strdup(" "));
	return (i);
}

int	tokenize_redirect(char *input, t_token *token)
{
	int	i;

	i = ft_isredirect(input);
	i *= (i > 0) - (i < 0);
	add_last(token, REDIRECT, ft_substr(input, 0, i));
	return (i - 1);
}

int	is_normal(char c)
{
	if (c == '|' || c == '"' || c == '\'' || c == '$')
		return (FALSE);
	if (ft_isblank(c) || c == '>' || c == '<')
		return (FALSE);
	return (TRUE);
}

int	tokenize_normal(char *input, t_token *token)
{
	int	i;

	i = 0;
	while (input[i] && is_normal(input[i]))
		i++;
	add_last(token, WORD, ft_substr(input, 0, i));
	return (i - 1);
}

t_token	*tokenize(char *input, t_env *env)
{
	int		i;
	t_token	*token;

	token = init_token();
	i = -1;
	while (input[++i])
	{
		if (input[i] == '"')
			i += tokenize_dquotes(input + i + 1, token, env);
		else if (input[i] == '\'')
			i += tokenize_squotes(input + i + 1, token);
		else if (ft_isblank(input[i]))
			i += tokenize_space(input + i + 1, token);
		else if (ft_isredirect(input + i))
			i += tokenize_redirect(input + i, token);
		else if (input[i] == '$')
			i += tokenize_envp(input + i + 1, token, env);
		else if (input[i] == '|')
			add_last(token, PIPE, ft_strdup("|"));
		else
			i += tokenize_normal(input + i, token);
	}
	return (token);
}

int	is_builtin(t_token *token)
{
	t_tnode		*node;
	char		*cmd;
	char		*temp;
	const char	*builtin = "cd\0echo\0env\0exit\0export\0pwd\0unset";

	node = token->head->next;
	cmd = ft_strdup("");
	while (node && node->type == WORD)
	{
		temp = cmd;
		cmd = ft_strjoin(cmd, node->str);
		free(temp);
		node = node->next;
	}
	temp = ft_strnstr(builtin, cmd, 34);
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
		remove_first(tokens);
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

void	clear_token(t_token *token)
{
	t_tnode	*node;
	t_tnode	*temp;

	node = token->head;
	while (node)
	{
		temp = node->next;
		free(node->str);
		free(node);
		node = temp;
	}
	free(token);
}

int	error(t_env *env, char *err_msg, int status)
{
	ft_putstr_fd("minishell: ", 2);
	if (!err_msg)
		err_msg = strerror(errno);
	ft_putendl_fd(err_msg, 2);
	env->exit_code = status;
	return (ERROR);
}

int	is_input_blank(char *input)
{
	while (ft_isblank(*input))
		input++;
	if (*input == '\0')
		return (TRUE);
	else
		return (FALSE);
}

int	get_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	redirect_check(char *input)
{
	int	result;

	while (*input)
	{
		result = ft_isredirect(input);
		if (result)
		{
			input += get_abs(result);
			while (ft_isblank(*input))
				input++;
			if (*input == '\0')
				return (ERROR);
			else if (ft_isredirect(input))
				return (ERROR);
		}
		else
			input++;	
	}
	return (0);
}

int	is_stdin(char *input)
{
	int		i;
	char	c;

	input = ft_strtrim(input, " \t");
	i = ft_strlen(input) - 1;
	if (i == -1)
	{
		free(input);
		return (TRUE);
	}
	c = input[i];
	free(input);
	if (i && c == '|')
		return (TRUE);
	return (FALSE);
}

char	*read_line(int *eof, char *line)
{
	char	*temp;
	char	*join;

	join = ft_strdup("");
	while (line)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			*eof = TRUE;
			break ;
		}
		temp = join;
		join = ft_strjoin(join, line);
		free(temp);
		if (!is_stdin(line))
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (join);
}
int	pipe_check(char **input);

int	last_pipe_check(char **input)
{
	int		eof;
	char	*join;
	char	*temp;

	if (pipe_check(input) == ERROR)
		return (0);
	if (!is_stdin(*input))
		return (0);
	eof = FALSE;
	join = read_line(&eof, (char *)1);
	if (eof == TRUE)
	{
		free(join);
		return (ERROR);
	}
	temp = *input;
	*input = ft_strjoin(*input, join);
	free(join);
	free(temp);
	return (0);
}

int	pipe_check(char **input)
{
	int	i;
	int	j;

	i = -1;
	while ((*input)[++i])
	{
		if ((*input)[i] == '|')
		{
			j = i - 1;
			while (j >= 0 && ft_isblank((*input)[j]))
				j--;
			if (j == -1)
				return (ERROR);
			else if ((*input)[j] == '|')
				return (ERROR);
			else if (ft_isredirect(*input + j))
				return (ERROR);
			else if (j != 0 && get_abs(ft_isredirect(*input + j - 1) == 2))
				return (ERROR);
		}
	}
	return (0);
}

int	syntax_check(char **input, t_env *env)
{
	if (**input == '\0' || is_input_blank(*input))
		return (ERROR);
	if (last_pipe_check(input) == ERROR)
		return (error(env, "syntax error: unexpected end of file", 258));
	if (redirect_check(*input) == ERROR)
		return (error(env, "syntax error near unexpected token", 258));
	if (pipe_check(input) == ERROR)
		return (error(env, "syntax error near unexpected token", 258));
	return (0);
}

char	*parse_cmd(char *argv)
{
	int	head;
	int	i;

	if (argv[ft_strlen(argv) - 1] == '/')
		return (argv);
	head = -1;
	i = 0;
	while (argv[i])
	{
		if (argv[i] == '/')
			head = i;
		i++;
	}
	head++;
	return (argv + head);
}

char	**parse_envp(char *envp[])
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*find_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*path;
	char	*temp;
	int		i;
	int		fd;

	paths = parse_envp(envp);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		fd = open(path, O_RDONLY);
		if (fd != ERROR)
		{
			close(fd);
			return (path);
		}
		free(path);
	}
	return (NULL);
}

void	child_error(char *err_msg, char *cmd, int status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_msg, 2);
	exit(status);
}

int	is_executable(char *cmd)
{
	int	fd;

	fd = open(cmd, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

int	is_directory(char *cmd)
{
	DIR	*result;

	result = opendir(cmd);
	if (!result)
		return (FALSE);
	closedir(result);
	return (TRUE);
}

void	execute(char **argv, char **envp)
{
	char	*path;
	char	*cmd;

	cmd = argv[0];
	argv[0] = parse_cmd(argv[0]);
	path = find_path(argv[0], envp);
	if (is_directory(cmd))
		child_error("is a directory", cmd, 126);
	if (!path)
	{
		if (is_executable(cmd))
			path = cmd;
		else if (ft_strchr(cmd, '/'))
			child_error("No such file or directory", cmd, 127);
		else
			child_error("command not found", cmd, 127);
	}
	if (ft_strchr(cmd, '/') && !is_executable(cmd))
		child_error("No such file or directory", cmd, 127);
	if (execve(path, argv, envp) == -1)
		child_error(strerror(errno), cmd, 1);
}

void	overwrite_output(char *filename, int *flag)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		child_error(strerror(errno), filename, 1);
	dup2(fd, STDOUT_FILENO);
	*flag = 1;
}

void	append_output(char *filename, int *flag)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 00644);
	if (fd == -1)
		child_error(strerror(errno), filename, 1);
	dup2(fd, STDOUT_FILENO);
	*flag = 1;
}

void	overwrite_input(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		child_error("No such file or directory", filename, 127);
	dup2(fd, STDIN_FILENO);
}

void	append_input(char *limiter)
{
	char	*line;
	int		fd;

	fd = open("./.heredoc", O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		child_error(strerror(errno), ".heredoc", 1);
	while (1)
	{
		ft_putstr_fd("> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	fd = open("./.heredoc", O_RDONLY);
	dup2(fd, STDIN_FILENO);
}

void	redirection(t_token *token, int *flag)
{
	char	*redirection;	
	char	*filename;
	char	*temp;

	redirection = remove_first(token);
	while (first_type(token) == BLANK)
		remove_first(token);
	filename = ft_strdup("");
	while (first_type(token) == WORD)
	{
		temp = filename;
		filename = ft_strjoin(filename, remove_first(token));
		free(temp);
	}
	if (ft_strcmp(redirection, ">") == 0)
		overwrite_output(filename, flag);
	else if (ft_strcmp(redirection, ">>") == 0)
		append_output(filename, flag);
	else if (ft_strcmp(redirection, "<") == 0)
		overwrite_input(filename);
	else if (ft_strcmp(redirection, "<<") == 0)
		append_input(filename);
	free(redirection);
	free(filename);
}

char	*child_preprocess(t_token *token, int fd[])
{
	int		out_redirection;
	char	*join;
	char	*temp;

	out_redirection = 0;
	join = ft_strdup("");
	while (first_type(token) != ERROR && first_type(token) != PIPE)
	{
		if (first_type(token) == REDIRECT)
		{
			redirection(token, &out_redirection);
			continue ;
		}
		temp = join;
		join = ft_strjoin(join, remove_first(token));
		free(temp);
	}
	close(fd[0]);
	if (!out_redirection && first_type(token) == PIPE)
		dup2(fd[1], STDOUT_FILENO);
	return (join);
}

int	parent_process(t_token *token, int fd[], pid_t pid, int oldfd)
{
	int		status;

	waitpid(pid, &status, 0);
	unlink("./.heredoc");
	close(fd[1]);
	if (last_type(token) == PIPE)
		dup2(fd[0], STDIN_FILENO);
	else
		dup2(oldfd, STDIN_FILENO);
	return (status >> 8);
}

void	child_process(t_token *token, int fd[], char *envp[])
{
	char	*join;
	char	**argv;

	if (first_type(token) == PIPE)
		remove_first(token);
	join = child_preprocess(token, fd);
	argv = ft_split(join, ' ');
	free(join);
	execute(argv, envp);
}

char	**convert_env(t_env *env)
{
	char	**envp;
	t_enode	*node;
	int		size;
	int		i;
	char	*temp;

	size = count_env(env);
	envp = malloc(sizeof(char *) * (size + 1));
	node = env->head->next;
	i = -1;
	while (++i < size)
	{
		temp = ft_strjoin(node->key, "=");
		envp[i] = ft_strjoin(temp, node->val);
		free(temp);
		node = node->next;
	}
	envp[i] = NULL;
	return (envp);
}

int	is_heredoc(t_token *token)
{
	t_tnode	*node;

	node = token->head->next;
	while (node)
	{
		if (node->type == REDIRECT && ft_strcmp(node->str, "<<") == 0)
				return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

void	external_process(t_token *token, t_env *env, int fd[], int oldfd)
{
	pid_t	pid;
	char	**envp;

	pid = fork();
	if (pid == ERROR)
		error(env, NULL, 1);
	if (pid == 0)
	{
		envp = convert_env(env);
		if (is_heredoc(token))
			dup2(oldfd, STDIN_FILENO);
		child_process(token, fd, envp);
	}
	else
		env->exit_code = parent_process(token, fd, pid, oldfd);
	clear_token(token);
}

void	execute_command(char *input, t_env *env)
{
	t_token	*tokens;
	t_token	*token;
	int		fd[2];
	int		oldfd;

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
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;
	int		is_error;

	env = init_envp(envp);
	receive_signal();
	while (argc || argv)
	{
		input = readline(get_prompt(env));
		if (input)
		{
			is_error = syntax_check(&input, env);
			if (*input)
				add_history(input);
			if (!is_error)
				execute_command(input, env);
			free(input);
		}
	}
	return (0);
}
