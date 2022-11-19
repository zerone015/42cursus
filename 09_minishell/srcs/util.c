/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:23:51 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/19 16:00:50 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/minishell.h"

void	ft_free(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

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
