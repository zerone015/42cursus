/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:09:44 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:03:14 by kijsong          ###   ########.fr       */
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

char	**make_argv(t_token *token)
{
	t_lst	*argv_list;
	char	**argv;
	char	*word;

	argv_list = NULL;
	while (first_type(token) != -1 && first_type(token) != PIPE)
	{
		if (first_type(token) == REDIRECT)
			redirection(token);
		if (first_type(token) == BLANK)
			free(remove_first(token));
		if (first_type(token) == WORD)
		{
			word = merge_word(token);
			convert_wildcard(word, &argv_list);
			free(word);
		}
	}
	argv = list_to_array(argv_list);
	ft_lstclear(&argv_list, NULL);
	return (argv);
}

void	child_external(t_exec *exec)
{
	char	**argv;
	char	**envp;
	int		temp_fd;

	temp_fd = dup(STDOUT_FILENO);
	dup2(exec->std_fd[WRITE_FD], STDOUT_FILENO);
	set_signal(CHILD);
	dup2(temp_fd, STDOUT_FILENO);
	envp = convert_env(exec->env);
	argv = make_argv(exec->token);
	child_execve(argv, envp);
}
