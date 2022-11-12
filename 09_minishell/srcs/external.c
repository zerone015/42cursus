/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:09:44 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:54:18 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../includes/minishell.h"

static int	is_heredoc(t_token *token)
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

static char	**convert_env(t_env *env)
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

void	child_external(t_exec *exec)
{
	char	**argv;
	char	**envp;

	set_signal(CHILD);
	envp = convert_env(exec->env);
	if (is_heredoc(exec->token))
		dup2(exec->std_fd[0], STDIN_FILENO);
	if (first_type(exec->token) == PIPE)
		free(remove_first(exec->token));
	argv = preprocess(exec->token, exec->pipe_fd);
	execute(argv, envp);
}
