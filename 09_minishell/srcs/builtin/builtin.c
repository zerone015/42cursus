/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:48:04 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/04 00:22:45 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	void		(*func)(int, char **, t_env *);
	const char	*builtin = "cd\0echo\0env\0exit\0export\0pwd\0unset";

	argc = 0;
	while (argv[argc])
		argc++;
	ft_memset(f, 0, sizeof(f));
	init_table(f);
	func = f[ft_strnstr(builtin, argv[0], 34) - builtin];
	func(argc, argv, env);
	exit(0);
}

void	child_builtin(t_token *token, int fd[], t_env *env)
{
	char	*join;
	char	**argv;

	if (first_type(token) == PIPE)
		remove_first(token);
	join = child_preprocess(token, fd);
	argv = ft_split(join, ' ');
	free(join);
	execute_builtin(argv, env);
}

int	parent_builtin(t_token *token, int fd[], pid_t pid, int oldfd)
{
	int		status;

	waitpid(pid, &status, 0);
	unlink("./.heredoc");
	close(fd[1]);
	if (last_type(token) == PIPE)
		dup2(fd[0], STDIN_FILENO);
	else
		dup2(oldfd, STDIN_FILENO);
	return (status >> 8);
}

void	builtin_process(t_token *token, t_env *env, int fd[], int oldfd)
{
	pid_t	pid;

	pid = fork();
	if (pid == ERROR)
		error(env, NULL, 1);
	if (pid == 0)
		child_builtin(token, fd, env);
	else
		env->exit_code = parent_builtin(token, fd, pid, oldfd);
	clear_token(token);
}
