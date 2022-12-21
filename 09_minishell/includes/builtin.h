/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:42:39 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:23:37 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "env.h"
# include "token.h"

enum e_builtin
{
	_CD = 1,
	_ECHO = 4,
	_ENV = 9,
	_EXIT = 13,
	_EXPORT = 18,
	_PWD = 25,
	_UNSET = 29
};

char	*strnstr_strict(const char *str, const char *to_find, size_t len);
int		has_pipe(t_token *token);
int		is_essential(char *arg);
int		builtin_error(t_env *env, char *cmd, char *arg, char *err_msg);
void	execute_builtin(char **argv, t_env *env, int is_child);
void	add_export(char *str, t_env *env);

int		builtin_cd(int argc, char *argv[], t_env *env);
int		builtin_echo(int argc, char *argv[], t_env *env);
int		builtin_env(int argc, char *argv[], t_env *env);
int		builtin_exit(int argc, char *argv[], t_env *env);
int		builtin_export(int argc, char *argv[], t_env *env);
int		builtin_pwd(int argc, char *argv[], t_env *env);
int		builtin_unset(int argc, char *argv[], t_env *env);

#endif
