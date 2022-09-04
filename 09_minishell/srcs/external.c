/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:09:44 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/05 00:11:27 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../includes/minishell.h"

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

void	child_process(t_token *token, int fd[], char *envp[])
{
	char	**argv;

	if (first_type(token) == PIPE)
		free(remove_first(token));
	argv = preprocess(token, fd);
	execute(argv, envp);
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

char	**convert_env(t_env *env)
{
	char	**envp;
	t_enode	*node;
	int		size;
	int		i;
	char	*temp;

	size = count_env(env);
	envp = safe_malloc(sizeof(char *) * (size + 1));
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

void	external_process(t_token *token, t_env *env, int fd[], int oldfd)
{
	pid_t	pid;
	char	**envp;

	pid = fork();
	if (pid == ERROR)
		error(env, NULL, 1);
	if (pid == 0)
	{
		set_signal(CHILD);
		envp = convert_env(env);
		if (is_heredoc(token))
			dup2(oldfd, STDIN_FILENO);
		child_process(token, fd, envp);
	}
	else
		env->exit_code = parent_process(token, fd, pid, oldfd);
}
