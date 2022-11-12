/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:25:06 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/12 20:10:13 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/minishell.h"

static int	redirect_check(char *input)
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
				return (-1);
			else if (ft_isredirect(input))
				return (-1);
		}
		else
			input++;
	}
	return (0);
}

static int	pipe_check(char **input)
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
				return (-1);
			else if ((*input)[j] == '|')
				return (-1);
			else if (ft_isredirect(*input + j))
				return (-1);
			else if (j != 0 && get_abs(ft_isredirect(*input + j - 1) == 2))
				return (-1);
		}
	}
	return (0);
}

static char	*read_line(int *eof, char *line)
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

static int	last_pipe_check(char **input)
{
	int		eof;
	char	*join;
	char	*temp;

	if (pipe_check(input) == -1)
		return (0);
	if (!is_stdin(*input))
		return (0);
	eof = FALSE;
	join = read_line(&eof, (char *)1);
	if (eof == TRUE)
	{
		free(join);
		return (-1);
	}
	temp = *input;
	*input = ft_strjoin(*input, join);
	free(join);
	free(temp);
	return (0);
}

int	check_syntax(char **input, t_env *env)
{
	if (**input == '\0' || is_input_blank(*input))
		return (-1);
	if (last_pipe_check(input) == -1)
		return (error(env, "syntax error: unexpected end of file", 258));
	if (redirect_check(*input) == -1)
		return (error(env, "syntax error near unexpected token", 258));
	if (pipe_check(input) == -1)
		return (error(env, "syntax error near unexpected token", 258));
	return (0);
}
