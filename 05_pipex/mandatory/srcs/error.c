/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:12:26 by yoson             #+#    #+#             */
/*   Updated: 2022/11/01 01:51:56 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	command_not_found(char *cmd)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd("command not found", STDERR_FILENO);
	exit(127);
}

void	ft_perror(char *input, int exit_code)
{
	if (input)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(input, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror(NULL);
	}
	else
		perror("pipex: ");
	exit(exit_code);
}

void	ft_strerror(void)
{
	char	*err_msg;

	err_msg = strerror(errno);
	while (wait(NULL) != -1)
		;
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
