/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:00:40 by son-yeong-w       #+#    #+#             */
/*   Updated: 2022/11/30 18:01:02 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	tokenize_null(t_token *token)
{
	add_last(token, WORD, ft_strdup(""));
	return (1);
}

int	tokenize_operator(char *input, t_token *token)
{
	if (!ft_strncmp(input, "&&", 2))
		add_last(token, LOGICAL, ft_strdup("&&"));
	else if (!ft_strncmp(input, "||", 2))
		add_last(token, LOGICAL, ft_strdup("||"));
	else if (*input == '|')
	{
		add_last(token, PIPE, ft_strdup("|"));
		return (0);
	}
	return (1);
}

int	tokenize_parenthesis(char *input, t_token *token)
{
	if (*input == '(')
		add_last(token, PARENTHESIS, ft_strdup("("));
	else if (*input == ')')
		add_last(token, PARENTHESIS, ft_strdup(")"));
	else
		return (0);
	return (1);
}
