/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:11:32 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/04 23:13:27 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*merge_word(t_token *token)
{
	char	*word;
	char	*temp;
	char	*first;

	word = ft_strdup("");
	while (first_type(token) == WORD)
	{
		temp = word;
		first = remove_first(token);
		word = ft_strjoin(word, first);
		free(temp);
		free(first);
	}
	return (word);
}

char	**make_argv(t_token *token, int size, int *flag)
{
	int		i;
	char	**argv;

	argv = safe_malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (first_type(token) != ERROR && first_type(token) != PIPE)
	{
		if (first_type(token) == REDIRECT)
			redirection(token, flag);
		if (first_type(token) == BLANK)
			free(remove_first(token));
		if (first_type(token) == WORD)
			argv[i++] = merge_word(token);
	}
	argv[i] = NULL;
	return (argv);
}

char	**preprocess(t_token *token, int fd[])
{
	int		out_redirection;
	char	**argv;

	out_redirection = 0;
	argv = make_argv(token, find_argv_size(token), &out_redirection);
	close(fd[0]);
	if (!out_redirection && first_type(token) == PIPE)
		dup2(fd[1], STDOUT_FILENO);
	return (argv);
}