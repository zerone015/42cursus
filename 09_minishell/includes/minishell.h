/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:13:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/31 20:37:40 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "list.h"
# include "queue.h"
# include "../libft/libft.h"

enum e_type
{
	WORD,
	BLANK,
	PIPE,
	REDIRECT
};

void	update_pwd(t_list *env);
char	*get_prompt(t_list *env);

#endif
