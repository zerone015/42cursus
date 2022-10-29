/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:12:26 by yoson             #+#    #+#             */
/*   Updated: 2022/10/30 08:11:26 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_error(char *err_msg, int exit_code)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(exit_code);
}

void	ft_perror(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

void	ft_strerror(void)
{
	char	*err_msg;

	err_msg = strerror(errno);
	while (wait(0) != -1)
		;
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
