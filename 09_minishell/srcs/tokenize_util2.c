/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:00:40 by son-yeong-w       #+#    #+#             */
/*   Updated: 2022/11/24 13:04:49 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int tokenize_null(t_token *token)
{
    add_last(token, WORD, ft_strdup(""));
    return (1);
}