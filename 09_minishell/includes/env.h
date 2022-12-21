/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:12:43 by yoson             #+#    #+#             */
/*   Updated: 2022/12/21 19:23:44 by kijsong          ###   ########.fr       */
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
void	delete_enode(t_env *env, t_enode *prev, t_enode *curr);
int		count_env(t_env *env);

#endif
