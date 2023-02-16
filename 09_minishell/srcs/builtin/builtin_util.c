/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:09:40 by kijsong           #+#    #+#             */
/*   Updated: 2023/02/16 19:27:54 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include "../../includes/minishell.h"

int	has_pipe(t_token *token)
{
	t_tnode	*node;

	node = token->head->next;
	while (node)
	{
		if (node->type == PIPE)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

int	builtin_error(t_env *env, char *cmd, char *arg, char *err_msg)
{
	if (!err_msg)
		err_msg = strerror(errno);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (arg)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(err_msg, STDERR_FILENO);
	env->exit_code = EXIT_FAILURE;
	return (1);
}

char	*strnstr_strict(const char *str, const char *to_find, size_t len)
{
	size_t	i;

	while (*to_find && len--)
	{
		i = 0;
		while ((const unsigned char)str[i] == (const unsigned char)to_find[i])
		{
			if (*(str - 1))
				break ;
			if (!to_find[i++])
				return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
