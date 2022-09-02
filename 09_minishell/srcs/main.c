/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:09:23 by yoson             #+#    #+#             */
/*   Updated: 2022/09/02 21:59:29 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h> //strerror
#include <unistd.h> //getcwd
#include <fcntl.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

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

	node = token->head;
	cmd = ft_strdup("");
	while (node->type == WORD)
	{
		temp = cmd;
		cmd = ft_strjoin(temp, node->str);
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
		return (TRUE);
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
		line = get_next_line(0);
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

char	*slash_ignore(char *argv)
{
	int	head;
	int	i;

	head = -1;
	i = 0;
	while (argv[i] && argv[i] != ' ')
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
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
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

	paths = parse_envp(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (NULL);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!path)
			return (NULL);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	execute(char **argv, char **envp, t_env *env)
{
	char	*path;

	argv[0] = slash_ignore(argv[0]);
	path = find_path(argv[0], envp);
	if (!path)
		error(env, "command not found", 127);
	if (execve(path, argv, envp) == -1)
		error(env, NULL, 1);
}

char	**preprocess(t_token *token, int fd[])
{
	char	*str;
	char	*join;
	char	*temp;

	join = ft_strdup("");
	while (first_type(token) != ERROR && first_type(token) != PIPE)
	{
		// if (first_type(token) == REDIRECT)
		// {
		// 	redirection(token);
		// 	continue ;
		// }	
		str = remove_first(token);
		temp = join;
		join = ft_strjoin(join, str);
		free(str);
		free(temp);
	}
	close(fd[0]);
	if (first_type(token) == PIPE)
		dup2(fd[1], STDOUT_FILENO);
	return (ft_split(join, ' '));
}

void	child_process(t_token *token, t_env *env, char *envp[], int oldfd)
{
	int		fd[2];
	int		status;
	pid_t	pid;
	char	**argv;

	if (pipe(fd) == -1)
		error(env, strerror(errno), 1);
	pid = fork();
	if (pid == ERROR)
		error(env, strerror(errno), 1);
	if (pid == 0)
	{
		argv = preprocess(token, fd);
		execute(argv, envp, env);
	}
	else
	{	
		waitpid(pid, &status, 0);
		close(fd[1]);
		if (last_type(token) == PIPE)
			dup2(fd[0], STDIN_FILENO);
		else
			dup2(oldfd, STDIN_FILENO);
		env->exit_code = status >> 24;
	}
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

void	external_process(t_token *token, t_env *env, int oldfd)
{
	char	**envp;

	envp = convert_env(env);
	child_process(token, env, envp, oldfd);
	clear_token(token);
}

void	execute_command(char *input, t_env *env)
{
	t_token	*tokens;
	t_token	*token;
	int		oldfd;

	oldfd = dup(STDIN_FILENO);
	tokens = tokenize(input, env);
	while (first_type(tokens) != ERROR)
	{
		token = parse_token(tokens);
		// if (is_builtin(token))
		// 	builtin_process(token, env);
		// else
		external_process(token, env, oldfd);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;
	int		is_error;

	env = init_envp(envp);
	// receive_signal();
	while (argc || argv)
	{
		input = readline(get_prompt(env));
		if (input)
		{
			is_error = syntax_check(&input, env);
			add_history(input);
			if (!is_error)
				execute_command(input, env);
			free(input);
		}
	}
	return (0);
}
