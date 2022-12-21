/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:13:21 by yoson             #+#    #+#             */
/*   Updated: 2022/12/21 17:15:10 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

pid_t	safe_fork(t_exec *exec)
{
	pid_t	pid;
	t_env	*env;

	pid = fork();
	if (pid == -1)
	{
		env = NULL;
		if (exec)
			env = exec->env;
		error(env, NULL, 1);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	safe_pipe(int pipe_fd[], t_exec *exec)
{
	if (pipe(pipe_fd) == -1)
	{
		error(exec->env, NULL, 1);
		exit(EXIT_FAILURE);
	}
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

int	find_exit_code(int status, int is_sigint)
{
	int		ret;

	if (is_normal_terminated(status))
	{
		if (is_sigint)
			ft_putstr_fd("\n", STDOUT_FILENO);
		ret = status >> 8;
	}
	else
	{
		if (is_quit(status))
		{
			ft_putstr_fd("Quit: ", STDOUT_FILENO);
			ft_putnbr_fd(status, STDOUT_FILENO);
		}
		ret = status + 128;
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	return (ret);
}
