/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:20:26 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/05 00:17:08 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include "../includes/minishell.h"

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
