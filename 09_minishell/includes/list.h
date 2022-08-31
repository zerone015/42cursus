/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:12:43 by yoson             #+#    #+#             */
/*   Updated: 2022/08/31 18:47:22 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef env_H
# define env_H

typedef struct s_lnode
{
	char			*key;
	char			*val;
	struct s_lnode	*next;
}	t_lnode;

typedef struct s_list
{
	t_lnode	*head;
	t_lnode	*tail;
}	t_list;

t_list	*init_list(void);
t_lnode	*find_key(t_list *env, char *key);
void	add_last(t_list *env, char *key, char *val);

#endif
