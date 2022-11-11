/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:48:04 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/12 04:27:51 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <term.h>
#include <unistd.h>
#include "../../includes/minishell.h"

void	init_table(void *f[])
{
	f[_CD] = builtin_cd;
	f[_ECHO] = builtin_echo;
	f[_ENV] = builtin_env;
	f[_EXIT] = builtin_exit;
	f[_EXPORT] = builtin_export;
	f[_PWD] = builtin_pwd;
	f[_UNSET] = builtin_unset;
}

void	execute_builtin(char **argv, t_env *env)
{
	int			argc;
	void		*f[30];
	int			(*func)(int, char **, t_env *);
	const char	*builtin = "\0cd\0echo\0env\0exit\0export\0pwd\0unset";

	argc = 0;
	while (argv[argc])
		argc++;
	ft_memset(f, 0, sizeof(f));
	init_table(f);
	func = f[strnstr_strict(builtin, argv[0], 35) - builtin];
	argc = -func(argc, argv, env);
	exit(argc);
}

void	builtin_process(t_token *token, t_env *env, int fd[], int std_fd[])
{
	if (first_type(token) == PIPE)
		free(remove_first(token));
	dup2(std_fd[0], STDIN_FILENO);
	execute_builtin(preprocess(token, fd), env);
}
