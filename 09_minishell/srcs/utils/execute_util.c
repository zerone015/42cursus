/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:51:23 by yoson             #+#    #+#             */
/*   Updated: 2022/12/02 12:48:18 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../../includes/minishell.h"

void	child_builtin(t_exec *exec)
{
	char	**argv;
	int		out_redirection;

	dup2(exec->std_fd[READ_FD], STDIN_FILENO);
	close(exec->pipe_fd[READ_FD]);
	if (first_type(exec->token) == PIPE)
		free(remove_first(exec->token));
	out_redirection = 0;
	argv = make_argv(exec->token, &out_redirection);
	if (!out_redirection && first_type(exec->token) == PIPE)
		dup2(exec->pipe_fd[WRITE_FD], STDOUT_FILENO);
	close(exec->pipe_fd[WRITE_FD]);
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

int	wait_all(pid_t last_pid, int *is_sigint)
{
	pid_t	pid;
	int		status;
	int		ret;

	status = 0;
	ret = 0;
	pid = 1;
	while (pid != -1)
	{
		pid = wait(&status);
		if (!is_normal_terminated(status) && status == 2)
			*is_sigint = TRUE;
		if (pid == last_pid)
			ret = status;
	}
	return (ret);
}

int	is_exit(t_tnode *first)
{
	if (first && ft_strncmp(first->str, "exit", 5) == 0)
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
