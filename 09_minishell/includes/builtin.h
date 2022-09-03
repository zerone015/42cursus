/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:42:39 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 22:04:44 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "env.h"
# include "token.h"

enum e_builtin
{
	_CD = 0,
	_ECHO = 3,
	_ENV = 8,
	_EXIT = 12,
	_EXPORT = 17,
	_PWD = 24,
	_UNSET = 28
};

void	builtin_process(t_token *token, t_env *env, int fd[], int oldfd);

void	builtin_cd(int argc, char *argv[], t_env *env);
void	builtin_echo(int argc, char *argv[], t_env *env);
void	builtin_env(int argc, char *argv[], t_env *env);
void	builtin_exit(int argc, char *argv[], t_env *env);
void	builtin_export(int argc, char *argv[], t_env *env);
void	builtin_pwd(int argc, char *argv[], t_env *env);
void	builtin_unset(int argc, char *argv[], t_env *env);

#endif
