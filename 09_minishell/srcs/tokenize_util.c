/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:18:52 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/04 23:27:30 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minishell.h"

int	ft_isredirect(char *input)
{
	if (ft_strncmp(input, "<<", 2) == 0)
		return (2);
	else if (ft_strncmp(input, ">>", 2) == 0)
		return (-2);
	else if (*input == '<')
		return (1);
	else if (*input == '>')
		return (-1);
	return (0);
}

int	tokenize_redirect(char *input, t_token *token)
{
	int	i;

	i = ft_isredirect(input);
	i *= (i > 0) - (i < 0);
	add_last(token, REDIRECT, ft_substr(input, 0, i));
	return (i - 1);
}

int	is_normal(char c)
{
	if (c == '|' || c == '"' || c == '\'' || c == '$')
		return (FALSE);
	if (ft_isblank(c) || c == '>' || c == '<')
		return (FALSE);
	return (TRUE);
}

int	tokenize_normal(char *input, t_token *token)
{
	int	i;

	i = 0;
	while (input[i] && is_normal(input[i]))
		i++;
	add_last(token, WORD, ft_substr(input, 0, i));
	return (i - 1);
}
