/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:09:44 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/30 16:11:39 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../includes/minishell.h"

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

int	find_argv_size(t_token *token)
{
	int		size;
	t_tnode	*node;

	size = 0;
	node = token->head->next;
	while (node)
	{
		if (node->type == REDIRECT)
		{
			node = node->next;
			if (node && node->type == BLANK)
				node = node->next;
			while (node && node->type != WORD)
				node = node->next;
		}
		else if (node->type == WORD)
		{
			size++;
			while (node && node->type == WORD)
				node = node->next;
		}
		else
			node = node->next;
	}
	return (size);
}

static char	**list_to_array(t_lst *list)
{
	int		count;
	int		index;
	char	**array;

	count = ft_lstsize(list) + 1;
	array = safe_malloc(count * sizeof(char *));
	index = 0;
	while (list)
	{
		array[index++] = list->content;
		list = list->next;
	}
	array[index] = NULL;
	return (array);
}

char	**make_argv(t_token *token, int *flag)
{
	int		i;
	t_lst	*argv_list;
	char	**argv;

	argv_list = NULL;
	i = 0;
	while (first_type(token) != -1 && first_type(token) != PIPE)
	{
		if (first_type(token) == REDIRECT)
			redirection(token, flag);
		if (first_type(token) == BLANK)
			free(remove_first(token));
		if (first_type(token) == WORD)
			convert_wildcard(merge_word(token), &argv_list);
	}
	argv = list_to_array(argv_list);
	ft_lstclear(&argv_list, NULL);
	return (argv);
}

void	child_external(t_exec *exec)
{
	char	**argv;
	char	**envp;
	int		out_redirection;

	set_signal(CHILD);
	envp = convert_env(exec->env);
	if (first_type(exec->token) == PIPE)
		free(remove_first(exec->token));
	out_redirection = 0;
	argv = make_argv(exec->token, &out_redirection);
	close(exec->pipe_fd[READ_FD]);
	if (!out_redirection && first_type(exec->token) == PIPE)
		dup2(exec->pipe_fd[WRITE_FD], STDOUT_FILENO);
	close(exec->pipe_fd[WRITE_FD]);
	child_execve(argv, envp);
}
