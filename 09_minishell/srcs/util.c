/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:23:51 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/04 23:29:58 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_input_blank(char *input)
{
	while (ft_isblank(*input))
		input++;
	if (*input == '\0')
		return (TRUE);
	else
		return (FALSE);
}

int	get_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	is_stdin(char *input)
{
	int		i;
	char	c;

	input = ft_strtrim(input, " \t");
	i = ft_strlen(input) - 1;
	if (i == -1)
	{
		free(input);
		return (TRUE);
	}
	c = input[i];
	free(input);
	if (i && c == '|')
		return (TRUE);
	return (FALSE);
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
