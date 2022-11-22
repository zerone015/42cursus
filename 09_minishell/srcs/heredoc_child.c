/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:13:53 by yoson             #+#    #+#             */
/*   Updated: 2022/11/22 22:15:42 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/minishell.h"

char	*find_env_next_address(char *str)
{
	if (*str == '$')
		str++;
	while (*str)
	{
		if (ft_isblank(*str) || (*str != '_' && !ft_isalnum(*str)))
			return (str);
		str++;
	}
	return (str);
}

char	*replace_env(char *str, t_env *env)
{
	char	*ret;
	char	*key;
	t_enode	*node;

	if (!ft_isalpha(str[1]) && str[1] != '_')
		ret = ft_substr(str, 0, find_env_next_address(str) - str);
	else if (ft_isdigit(str[1]))
		ret = ft_strdup("");
	else
	{
		key = ft_substr(str, 1, find_env_next_address(str) - str - 1);
		node = find_key(env, key);
		if (node)
			ret = ft_strdup(node->val);
		else
			ret = ft_strdup("");
		free(key);
	}
	return (ret);
}

char	*parse_input(char *input, t_env *env)
{
	char	*temp;
	char	*join;

	join = ft_strdup("");
	while (*input)
	{
		temp = join;
		if (*input == '$' && input[1] == '\0')
			join = ft_strjoin(join, "$");
		else if (ft_strchr(input, '$'))
		{
			join = ft_strjoin(join, ft_substr(input, 0, ft_strchr(input, '$') - input));
			free(temp);
			temp = join;
			input = ft_strchr(input, '$');
			join = ft_strjoin(join, replace_env(input, env));
			input = find_env_next_address(input);
		}
		else
		{
			join = ft_strjoin(join, input);
			input = ft_strrchr(input, '\0');
		}
		free(temp);
	}
	return (join);
}

static char	*read_input(char *limiter, t_env *env)
{
	char	*input;
	char	*join;
	char	*temp;

	echoctl(FALSE);
	join = ft_strdup("");
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		input = get_next_line(STDIN_FILENO);
		if (input == NULL || ft_strcmp(input, limiter) == 0)
			break ;
		if (ft_strchr(input, '$'))
		{
			temp = input;
			input = parse_input(input, env);
			free(temp);
		}
		temp = join;
		join = ft_strjoin(join, input);
		free(temp);
	}
	return (join);
}

static void	input_to_file(char *input, char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		child_error(NULL, "heredoc", 1);
	write(fd, input, ft_strlen(input));
	close(fd);
}

static void	make_heredocs(t_token *token, t_exec *exec)
{
	t_tnode	*cur;
	char	*input;

	cur = find_heredoc_limiter(token->head->next);
	while (cur)
	{
		input = read_input(ft_strjoin(cur->str, "\n"), exec->env);
		input_to_file(input, *(exec->heredocs)++);
		free(input);
		cur = find_heredoc_limiter(cur);
	}
}

void	child_heredoc(t_token *token, t_exec *exec)
{
	set_signal(CHILD);
	make_heredocs(token, exec);
	exit(EXIT_SUCCESS);
}
