/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:12:43 by yoson             #+#    #+#             */
/*   Updated: 2022/11/12 16:31:09 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_enode
{
	char			*key;
	char			*val;
	struct s_enode	*next;
}	t_enode;

typedef struct s_env
{
	int		exit_code;
	t_enode	*head;
	t_enode	*tail;
}	t_env;

t_env	*init_env(void);
t_enode	*find_key(t_env *env, char *key);
void	add_enode(t_env *env, char *key, char *val);
void	delete_enode(t_enode *node);
int		count_env(t_env *env);

#endif
